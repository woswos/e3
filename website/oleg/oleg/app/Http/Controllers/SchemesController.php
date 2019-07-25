<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Scheme;
use App\Solution;

class SchemesController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        //
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        //Find the corresponding benchmark
        $benchmarks = Scheme::all();


        $benchmarks_charts = array();

        foreach ($benchmarks as $benchmark) {
            // Prepare chart data
            $chart_values = array(
              "operation" => array(),
              "speed" => array()
            );

            if($benchmark != null){
                // Create an array that has a unique entry
                $speed_array = json_decode($benchmark->speed, true);

                if($speed_array != null){
                    $speed_array_gates = array();
                    $speed_array_32 = array();
                    $speed_array_8 = array();

                    foreach ($speed_array as $key => $value) {
                        if (strpos($key, '_32') !== false) {
                            $speed_array_32[$key] = $value;
                        } else if (strpos($key, '_8') !== false){
                            $speed_array_8[$key] = $value;
                        } else {
                            $speed_array_gates[$key] = $value;
                        }
                    }

                    arsort($speed_array_gates);
                    arsort($speed_array_32);
                    arsort($speed_array_8);

                    $speed_array = array_merge($speed_array_32, $speed_array_8, $speed_array_gates);


                    foreach ($speed_array as $key => $value) {
                      $chart_values["operation"][] = $key;
                      $chart_values["speed"][] = $value;
                    }
                } else {
                    $chart_values = "none";
                }

            } else {
                $chart_values = "none";
            }

            $benchmarks_charts[$benchmark->id] = $chart_values;
        }



        $data = array(
            'benchmarks' => $benchmarks,
            'benchmarks_charts' => $benchmarks_charts,
            "chart_mode" => "benchmark",
            "chart_type" => "line"
          );

        return view('schemes/create')->with($data);
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
            'attached_files' => 'required'
        ];

        $customMessages = [
            'attached_files.required' => 'You need to attach your code'
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

        // Create a scheme
        $scheme = new Scheme;
        $scheme->name = $request->input('name');
        $scheme->email = $request->input('email');
        $scheme->money = 0;
        $scheme->attached_files = $fileNameToStore;
        $scheme->save();

        return redirect()->route('scheme.create')->with('success', ' Encryption scheme submitted successfully');
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function solutionStore(Request $request)
    {
        $rules = [
            'attached_files' => 'required',
            'name' => 'required',
            'secret_string' => 'required'
        ];

        $customMessages = [
            'attached_files.required' => 'You need to attach your explanation',
            'name.required' => 'Please provide your name',
            'email.required' => 'Please provide your email',
            'secret_string.required' => 'Please provide the secret string'
        ];

        $this->validate($request, $rules, $customMessages);

        # Secret value check
        $scheme = Scheme::Find($request->input('scheme_id'));
        if($scheme->secret_string != $request->input('secret_string')){
            return redirect()->route('scheme.create')->with('error', 'Secret string is wrong!');
        }


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
            $path = $request->file('attached_files')->storeAs('public/attached_files_solutions', $fileNameToStore);
        } else {
            $fileNameToStore = 'none';
        }

        // Create a scheme
        $solution = new Solution;
        $solution->scheme_id = $request->input('scheme_id');
        $solution->name = $request->input('name');
        $solution->email = $request->input('email');
        $solution->attached_files = $fileNameToStore;
        $solution->secret_string = $request->input('secret_string');
        $solution->save();

        return redirect()->route('scheme.create')->with('success', 'Congratulations! Solution submitted successfully');
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit($id)
    {
        //
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
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        //
    }
}
