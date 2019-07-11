<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\User;

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
    public function create()
    {
        //
        return view('benchmarks/create');
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        //
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        $schemes = User
                    ::join('schemes', 'users.id', '=', 'schemes.user_id')
                    ->join('benchmarks', 'schemes.id', '=', 'benchmarks.scheme_id')
                    ->where('schemes.id', $id)
                    //->select('users.id', 'contacts.phone', 'orders.price')
                    //->getQuery() // Optional: downgrade to non-eloquent builder so we don't build invalid User objects.
                    //->toSql();
                    ->get();
        //dd($schemes);


        // Prepare chart data
        $chart_values = array(
            "operation" => array(),
            "speed" => array()
        );

        // Create an array that has a unique entry
        foreach($schemes as $scheme){
            $speed_array = json_decode($scheme->speed, true);
            foreach ($speed_array as $key => $value) {
                $chart_values["operation"][] = $key;
                $chart_values["speed"][] = $value;
            }
        }

        //dd($chart_values);

        $data = array(
            'schemes' => $schemes,
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
