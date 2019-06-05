<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

// Include the namespace from scheme and challenge for accesing to database
use App\Scheme;
use App\Challenge;

class PagesController extends Controller
{

    public function index(){

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
          'totalPrizeAvailable' => $totalPrizeAvailable,
          'totalPrizeChallenges' => $totalPrizeChallenges,
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
}
