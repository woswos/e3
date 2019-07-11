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
                    //->select('users.id', 'contacts.phone', 'orders.price')
                    //->getQuery() // Optional: downgrade to non-eloquent builder so we don't build invalid User objects.
                    //->toSql();
                    ->get();
        //dd($schemes);

        // Prepare chart data
        $chart_values = array(
            "scheme_title" => array(),
            "operation" => array(),
            "speed" => array(),
            "prize" => array()
        );

        // Create an array that has a unique entry
        foreach($schemes as $scheme){
            $speed_array = json_decode($scheme->speed, true);
            foreach ($speed_array as $key => $value) {
                $chart_values["scheme_title"][] = $scheme->title;
                $chart_values["operation"][] = $key;
                $chart_values["speed"][] = $value;
                $chart_values["prize"][] = $scheme->total_prize;
            }
        }


        // Create an array that has a unique entry for each operation like and, nand, etc
        $ordered_chart_values = array();
        $i = 0;
        foreach ($chart_values["operation"] as $key => $value) {

            $ordered_chart_values[$value][$chart_values["scheme_title"][$i]]["speed"] = $chart_values["speed"][$i];
            $ordered_chart_values[$value][$chart_values["scheme_title"][$i]]["prize"] = $chart_values["prize"][$i];

            $i = $i + 1;
        }

        //dd($ordered_chart_values);

        $data = array(
            'schemes' => $schemes,
            'chart_values' => $ordered_chart_values,
            "chart_mode" => "benchmark"
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
