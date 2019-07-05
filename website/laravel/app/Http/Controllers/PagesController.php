<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

// Include the namespace from scheme and challenge for accesing to database
use App\Scheme;
use App\Challenge;
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

        // Get all schemes
        $schemes = Scheme::all();
        $totalSchemes = $schemes->count();

        // Get top 5 schemes from db
        $topSchemes = Scheme::all()->take(5);

        // Get top 5 hackers from db
        $topHackers = Scheme::all()->take(5);

        // Count number of available challenges
        $allUnsolvedChallenge = Challenge::where('solved', 'false')->get();
        $totalPrizeChallenges = $allUnsolvedChallenge->count();

        // Count amount of available prize
        $totalPrizeAvailable = Challenge::where('solved', 'false')->sum('prize');

        // Get latest 4 schemes from db
        $recentlySubmittedSchemes = Scheme::orderBy('id','DESC')->take(3)->get();

        $data = array(
            'schemes' => $schemes,
            'totalPrizeAvailable' => $totalPrizeAvailable,
            'totalPrizeChallenges' => $totalPrizeChallenges,
            'totalSchemes' => $totalSchemes,
            'topSchemes' => $topSchemes,
            'topHackers' => $topHackers,
            'recentlySubmittedSchemes' => $recentlySubmittedSchemes,
        );

        return view('pages/index')->with($data);
    }


    public function about(){
        $data = array();
        return view('pages/about')->with($data);
    }


    public function ranking(){
        // Get all schemes from db
        $schemes = Scheme::all();

        $data = array(
            'schemes' => $schemes
        );

        // Convert array to string
        /*
        $chart_X = json_encode($chart_schemes_X);
        $chart_Y = json_encode($chart_schemes_Y);
        $chart_l = json_encode($chart_labels);

        $data = array(
        'chart_X' => $chart_X,
        'chart_Y' => $chart_Y,
        'chart_l' => $chart_l
        );
        */

        return view('pages/ranking')->with($data);
    }


    public function faq(){
        $data = array();
        return view('pages/faq')->with($data);
    }
}
