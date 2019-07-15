<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

// Include the namespace from scheme and challenge for accesing to database
use App\Scheme;
use App\Challenge;
use App\Queue;
use App\Implementation;
use App\User;

class SchemesController extends Controller
{
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct()
    {
        $this->middleware('auth', ['except' => ['index', 'show']]);
    }

    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        // Get all schemes from db
        $schemes = Scheme::orderBy('id','DESC')->get();

        //$user_id = auth()->user()->id;
        //$user_schemes = Scheme::where('user_id', $user_id)->get();

        $data = array(
          'schemes' => $schemes
          );

        return view('schemes/index')->with($data);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        //
        return view('schemes/create');
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {

        $rules = [
            'title' => 'required',
            'authors' => 'required',
            'abstract' => 'required',
            'institutions' => 'required',
            'attached_files' => 'required|max:50000',
            'link' => 'nullable | url'
        ];

        $customMessages = [
            //'attached_files_implementation.required' => 'You cannot leave implementation part empty'
            'attached_files.required' => 'You need to attach the paper.',
            'link.url' => 'Link needs to be an URL.'
        ];

        $this->validate($request, $rules, $customMessages);



        // Handle File Upload - Theory
        if($request->hasFile('attached_files')){
            // Get filename with the extension
            $filenameWithExt = $request->file('attached_files')->getClientOriginalName();
            // Get just filename
            $filename = pathinfo($filenameWithExt, PATHINFO_FILENAME);
            // Get just ext
            $extension = $request->file('attached_files')->getClientOriginalExtension();
            // Filename to store
            $fileNameToStore= $filename.'_'.time().'.'.$extension;
            // Upload Image
            $path = $request->file('attached_files')->storeAs('public/attached_files', $fileNameToStore);
        } else {
            $fileNameToStore = 'none';
        }

        // Handle File Upload - Implementation
        if($request->hasFile('attached_files_implementation')){
            // Get filename with the extension
            $filenameWithExt = $request->file('attached_files_implementation')->getClientOriginalName();
            // Get just filename
            $filename = pathinfo($filenameWithExt, PATHINFO_FILENAME);
            // Get just ext
            $extension = $request->file('attached_files_implementation')->getClientOriginalExtension();
            // Filename to store
            $implementationFileNameToStore= $filename.'_'.time().'.'.$extension;
            // Upload Image
            $path = $request->file('attached_files_implementation')->storeAs('public/attached_files_implementation', $implementationFileNameToStore);
        } else {
            $implementationFileNameToStore = 'none';
        }

        // Create a scheme
        $scheme = new Scheme;
        $scheme->title = $request->input('title');
        $scheme->authors = $request->input('authors');
        $scheme->institutions = $request->input('institutions');
        $scheme->abstract = $request->input('abstract');
        $scheme->keywords = $request->input('keywords');
        $scheme->total_prize = 0;
        $scheme->total_attempts = 0;
        $scheme->attached_files = $fileNameToStore;
        $scheme->user_id = auth()->user()->id;
        $scheme->save();

        // Get latest submitted scheme's id
        $lastSchemes = Scheme::orderBy('id','DESC')->take(1)->get();
        $lastScheme = $lastSchemes[0];
        $lastSchemeId = $lastScheme['id'];


        // Create a scheme implementation
        $implementation = new Implementation;
        $implementation->scheme_id = $lastSchemeId;
        $implementation->programming_language = $request->input('programming_language');
        $implementation->programming_language_other = $request->input('programming_language_other');

        if(null !== ($request->input('supported_operations'))){
            $operationsvalue = implode(",", $request->input('supported_operations'));
        }else{
            $operationsvalue = null;
        }

        if(null !== ($request->input('gate'))){
            $gatevalue = implode(",", $request->input('gate'));
        }else{
            $gatevalue = null;
        }

        if(null !== ($request->input('arithmetic'))){
            $arithmeticvalue = implode(",", $request->input('arithmetic'));
        }else{
            $arithmeticvalue = null;
        }

        $implementation->supported_operations = $operationsvalue;
        $implementation->gate = $gatevalue;
        $implementation->arithmetic = $arithmeticvalue;
        $implementation->link = $request->input('link');
        $implementation->attached_files_implementation = $implementationFileNameToStore;
        $implementation->save();


        // Add submitted scheme to the processing queue
        $queue = new Queue;
        $queue->scheme_id = $lastSchemeId;
        $queue->processed = 0;
        $queue->save();

        return redirect()->route('scheme.show', ['id' => $lastSchemeId])->with('success', 'Encryption scheme submitted successfully');

    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {

        $scheme = User
                    ::join('schemes', 'users.id', '=', 'schemes.user_id')
                    ->where('schemes.id', $id)
                    //->select('users.id', 'contacts.phone', 'orders.price')
                    ->getQuery() // Optional: downgrade to non-eloquent builder so we don't build invalid User objects.
                    //->toSql();
                    ->first();

        $schemeWithBenchmark = User
                                ::join('schemes', 'users.id', '=', 'schemes.user_id')
                                ->join('benchmarks', 'schemes.id', '=', 'benchmarks.scheme_id')
                                ->where('schemes.id', $id)
                                //->select('users.id', 'contacts.phone', 'orders.price')
                                ->getQuery() // Optional: downgrade to non-eloquent builder so we don't build invalid User objects.
                                //->toSql();
                                ->first();
        //dd($scheme);


        //Find the corresponding implementation
        $implementation = Implementation::where('scheme_id', $id)->get();

        //Find the challenges by id which is given in the url
        $challenges = Challenge::where('scheme_id', $id)->get();

        // Prepare chart data
        $chart_values = array(
          "operation" => array(),
          "speed" => array()
        );

        if($schemeWithBenchmark != null){
            // Create an array that has a unique entry
            $speed_array = json_decode($schemeWithBenchmark['speed'], true);
            foreach ($speed_array as $key => $value) {
              $chart_values["operation"][] = $key;
              $chart_values["speed"][] = $value;
            }
        } else {
            $chart_values = "none";
        }

        //dd($chart_values);

        /*
        $test = '{"nand":"'.mt_rand(1,100).'","and":"'.mt_rand(1,100).'","not":"'.mt_rand(1,100).'","xor":"'.mt_rand(1,100).'","xnor":"'.mt_rand(1,100).'","mux":"'.mt_rand(1,100).'","nor":"'.mt_rand(1,100).'","or":"'.mt_rand(1,100).'","add_8":"'.mt_rand(1,100).'","add_32":"'.mt_rand(1,100).'","div_8":"'.mt_rand(1,100).'","div_32":"'.mt_rand(1,100).'","mul_8":"'.mt_rand(1,100).'","mul_32":"'.mt_rand(1,100).'"}';
        dd($test);
        */

        $data = array(
          'scheme' => $scheme,
          'challenges' => $challenges,
          'implementation' => $implementation,
          'chart_values' => $chart_values,
          "chart_mode" => "benchmark",
          "chart_type" => "line"
        );


        return view('schemes/show')->with($data);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit($id)
    {

        //Find the scheme by id which is given in the url
        $scheme = Scheme::find($id);


        // Check if user is the scheme author
        if (auth()->user()->id === $scheme->user_id) {
            //Find the corresponding implementation
            $implementation = Implementation::where('scheme_id', $id)->get();

            //Find the challenges by id which is given in the url
            $challenges = Challenge::where('scheme_id', $id)->get();

            $data = array(
              'scheme' => $scheme,
              'challenges' => $challenges,
              'implementation' => $implementation
              );

            return view('schemes/edit')->with($data);

        } else {

            return redirect()->route('scheme.show', ['id' => $id]);
        }


    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, $id)
    {
        $rules = [
            'title' => 'required',
            'authors' => 'required',
            'abstract' => 'required',
            'institutions' => 'required',
            'link' => 'nullable | url'
        ];

        $customMessages = [
            //'attached_files_implementation.required' => 'You cannot leave implementation part empty'
            'attached_files.required' => 'You need to attach the paper.',
            'link.url' => 'Link needs to be an URL.'
        ];

        $this->validate($request, $rules, $customMessages);



        // Handle File Upload - Theory
        if($request->hasFile('attached_files')){
            // Get filename with the extension
            $filenameWithExt = $request->file('attached_files')->getClientOriginalName();
            // Get just filename
            $filename = pathinfo($filenameWithExt, PATHINFO_FILENAME);
            // Get just ext
            $extension = $request->file('attached_files')->getClientOriginalExtension();
            // Filename to store
            $fileNameToStore= $filename.'_'.time().'.'.$extension;
            // Upload Image
            $path = $request->file('attached_files')->storeAs('public/attached_files', $fileNameToStore);
        } else {
            $fileNameToStore = 'none';
        }

        // Handle File Upload - Implementation
        if($request->hasFile('attached_files_implementation')){
            // Get filename with the extension
            $filenameWithExt = $request->file('attached_files_implementation')->getClientOriginalName();
            // Get just filename
            $filename = pathinfo($filenameWithExt, PATHINFO_FILENAME);
            // Get just ext
            $extension = $request->file('attached_files_implementation')->getClientOriginalExtension();
            // Filename to store
            $implementationFileNameToStore= $filename.'_'.time().'.'.$extension;
            // Upload Image
            $path = $request->file('attached_files_implementation')->storeAs('public/attached_files_implementation', $implementationFileNameToStore);
        } else {
            $implementationFileNameToStore = 'none';
        }

        // Create a scheme
        $scheme = Scheme::find($id);
        $scheme->title = $request->input('title');
        $scheme->authors = $request->input('authors');
        $scheme->institutions = $request->input('institutions');
        $scheme->abstract = $request->input('abstract');
        $scheme->keywords = $request->input('keywords');
        if($fileNameToStore != "none"){
            $scheme->attached_files = $fileNameToStore;
        }
        $scheme->user_id = auth()->user()->id;
        $scheme->save();

        // Create a scheme implementation
        $implementation = Implementation::where('scheme_id', $id)->first();
        $implementation->scheme_id = $id;
        $implementation->programming_language = $request->input('programming_language');
        $implementation->programming_language_other = $request->input('programming_language_other');

        if(null !== ($request->input('supported_operations'))){
            $operationsvalue = implode(",", $request->input('supported_operations'));
        }else{
            $operationsvalue = null;
        }

        if(null !== ($request->input('gate'))){
            $gatevalue = implode(",", $request->input('gate'));
        }else{
            $gatevalue = null;
        }

        if(null !== ($request->input('arithmetic'))){
            $arithmeticvalue = implode(",", $request->input('arithmetic'));
        }else{
            $arithmeticvalue = null;
        }

        $implementation->supported_operations = $operationsvalue;
        $implementation->gate = $gatevalue;
        $implementation->arithmetic = $arithmeticvalue;
        $implementation->link = $request->input('link');
        if($implementationFileNameToStore != "none"){
            $implementation->attached_files_implementation = $implementationFileNameToStore;
        }
        $implementation->save();


        // Add submitted scheme to the processing queue
        $queue = new Queue;
        $queue->scheme_id = $id;
        $queue->processed = 0;
        $queue->save();

        return redirect()->route('scheme.show', ['id' => $id])->with('success', 'Encryption scheme updated successfully');
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        // Find passed scheme and delete
        $scheme = scheme::find($id);
        $scheme->delete();

        return redirect('scheme')->with('success', 'Scheme removed successfully');
    }
}
