<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

// Include the namespace from scheme and challenge for accesing to database
use App\Scheme;
use App\Challenge;
use App\Solution;
use App\User;
use App\Benchmark;
use Cookie;

class PagesController extends Controller
{

    public function index(){

        /*
        if(Cookie::has('first_time') == false){
            Cookie::queue('first_time', 'yes', 60);
        } else {
            Cookie::queue('first_time', 'no', 60);
        }
        */


        $schemes = User
                    ::join('schemes', 'users.id', '=', 'schemes.user_id')
                    //->join('benchmarks', 'schemes.id', '=', 'benchmarks.scheme_id')
                    //->select('users.id', 'contacts.phone', 'orders.price')
                    //->getQuery() // Optional: downgrade to non-eloquent builder so we don't build invalid User objects.
                    //->toSql();
                    ->get();

        $schemesWithBenchmark = User
                                ::join('schemes', 'users.id', '=', 'schemes.user_id')
                                ->join('benchmarks', 'schemes.id', '=', 'benchmarks.scheme_id')
                                //->select('users.id', 'contacts.phone', 'orders.price')
                                //->getQuery() // Optional: downgrade to non-eloquent builder so we don't build invalid User objects.
                                //->toSql();
                                ->get();
        //dd($schemes);

        // Get all schemes
        //$schemes = Scheme::all();
        $totalSchemes = $schemes->count();

        // Get top 5 schemes from db
        //$topSchemes = Scheme::all()->take(5);
        $topSchemes = $schemes->take(5);

        // Get top 5 hackers from db
        $topHackers = Solution::all()->take(5);

        // Count number of available challenges
        $allUnsolvedChallenge = Challenge::where('solved', 'false')->get();
        $totalPrizeChallenges = $allUnsolvedChallenge->count();

        // Count amount of available prize
        $totalPrizeAvailable = Challenge::where('solved', 'false')->sum('prize');

        // Get latest 4 schemes from db
        $recentlySubmittedSchemes = Scheme::orderBy('id','DESC')->take(3)->get();

        // Prepare chart data
        $chart_values = array(
            "scheme_title" => array(),
            "operation" => array(),
            "speed" => array(),
            "prize" => array()
        );


        // Create an array that has a unique entry
        foreach($schemesWithBenchmark as $scheme){
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
            'totalPrizeAvailable' => $totalPrizeAvailable,
            'totalPrizeChallenges' => $totalPrizeChallenges,
            'totalSchemes' => $totalSchemes,
            'topSchemes' => $topSchemes,
            'topHackers' => $topHackers,
            'recentlySubmittedSchemes' => $recentlySubmittedSchemes,
            'chart_values' => $ordered_chart_values,
            "chart_mode" => "index",
            "chart_type" => "scatter"
        );

        return view('pages/index')->with($data);
    }


    public function about(){
        $data = array();
        return view('pages/about')->with($data);
    }


    public function ranking(){
        // Get all schemes from db
        $schemes = User
                    ::join('schemes', 'users.id', '=', 'schemes.user_id')
                    ->get();

        $schemesWithBenchmark = User
                                ::join('schemes', 'users.id', '=', 'schemes.user_id')
                                ->join('benchmarks', 'schemes.id', '=', 'benchmarks.scheme_id')
                                ->get();

        // Prepare chart data
        $chart_values = array(
            "scheme_title" => array(),
            "operation" => array(),
            "speed" => array(),
            "prize" => array()
        );

        // Create an array that has a unique entry
        foreach($schemesWithBenchmark as $scheme){
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

        $data = array(
            'schemes' => $schemes,
            'chart_values' => $ordered_chart_values,
            "chart_mode" => "index",
            "chart_type" => "scatter"
        );

        return view('pages/ranking')->with($data);
    }


    public function faq(){
        $data = array();
        return view('pages/faq')->with($data);
    }
}
