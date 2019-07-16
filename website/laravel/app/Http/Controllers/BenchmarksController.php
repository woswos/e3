<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

// Include the namespace from scheme and challenge for accesing to database
use App\Scheme;
use App\Challenge;
use App\Solution;
use App\User;
use App\Queue;
use App\Benchmark;

class BenchmarksController extends Controller
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
    public function create($scheme_id = 0)
    {
        // If url was manually changed, redirect to scheme listing page
        if($scheme_id == 0){
          return redirect('scheme');
        } else {
          $scheme = Scheme::find($scheme_id);
          return view('benchmarks/create')->with('scheme', $scheme);
        }

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
            'attached_files_benchmark' => 'required',
            'supported_operations.0' =>'required_without:supported_operations.1',
            //'supported_operations.1' =>'required_without:supported_operations.0'
        ];

        $customMessages = [
            //'attached_files_implementation.required' => 'You cannot leave implementation part empty'
            'attached_files_benchmark.required' => 'You need to attach the code.',
            'supported_operations.0.required_without' => 'You need to select whether you implemented gate or arithmetic operations.',
            //'supported_operations.1.required_without' => null
        ];

        $this->validate($request, $rules, $customMessages);


        // Handle File Upload - Benchmark
        if($request->hasFile('attached_files_benchmark')){
            // Get filename with the extension
            $filenameWithExt = $request->file('attached_files_benchmark')->getClientOriginalName();
            // Get just filename
            $filename = pathinfo($filenameWithExt, PATHINFO_FILENAME);
            // Get just ext
            $extension = $request->file('attached_files_benchmark')->getClientOriginalExtension();
            // Filename to store
            $benchmarkFileNameToStore= $filename.'_'.time().'.'.$extension;
            // Upload Image
            $path = $request->file('attached_files_benchmark')->storeAs('public/attached_files_benchmark', $benchmarkFileNameToStore);
        } else {
            $benchmarkFileNameToStore = 'none';
        }

        // Create a new benchmark
        $benchmark = new Benchmark;
        $benchmark->scheme_id = $request->input('scheme_id');
        $benchmark->programming_language = $request->input('programming_language');
        $benchmark->programming_language_other = $request->input('programming_language_other');

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

        $benchmark->supported_operations = $operationsvalue;
        $benchmark->gate = $gatevalue;
        $benchmark->arithmetic = $arithmeticvalue;
        $benchmark->attached_files = $benchmarkFileNameToStore;
        $benchmark->save();

        // Add submitted scheme to the processing queue
        $queue = new Queue;
        $queue->scheme_id = $request->input('scheme_id');
        $queue->processed = 0;
        $queue->save();

        return redirect()->route('scheme.show', ['id' => $request->input('scheme_id')])->with('success', 'Benchmark submitted successfully');

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
                    ->join('benchmarks', 'schemes.id', '=', 'benchmarks.scheme_id')
                    ->where('schemes.id', $id)
                    //->select('users.id', 'contacts.phone', 'orders.price')
                    ->getQuery() // Optional: downgrade to non-eloquent builder so we don't build invalid User objects.
                    //->toSql();
                    ->first();
        //dd($schemes);


        // Prepare chart data
        $chart_values = array(
            "operation" => array(),
            "speed" => array()
        );

        // Create an array that has a unique entry
        $speed_array = json_decode($scheme->speed, true);
        foreach ($speed_array as $key => $value) {
            $chart_values["operation"][] = $key;
            $chart_values["speed"][] = $value;
        }


        //dd($chart_values);

        /*
        $test = '{"nand":"'.mt_rand(1,100).'","and":"'.mt_rand(1,100).'","not":"'.mt_rand(1,100).'","xor":"'.mt_rand(1,100).'","xnor":"'.mt_rand(1,100).'","mux":"'.mt_rand(1,100).'","nor":"'.mt_rand(1,100).'","or":"'.mt_rand(1,100).'","add_8":"'.mt_rand(1,100).'","add_32":"'.mt_rand(1,100).'","div_8":"'.mt_rand(1,100).'","div_32":"'.mt_rand(1,100).'","mul_8":"'.mt_rand(1,100).'","mul_32":"'.mt_rand(1,100).'"}';
        dd($test);
        */

        $data = array(
            'scheme' => $scheme,
            'chart_values' => $chart_values,
            "chart_mode" => "benchmark",
            "chart_type" => "line"
        );

        return view('benchmarks/show')->with($data);
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
