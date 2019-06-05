<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class PagesController extends Controller
{

    public function index(){
      $data = array(
          'totalPrizeAvailable' => '0',
          'totalPrizeChallenges' => '0',
          'topSchemes' => [['1', 'Programming', 'SEO', 'test'],
                           ['2', 'Programming', 'SEO', 'test'],
                           ['3', 'Programming', 'SEO', 'test']],
          'topHackers' => [['1', 'Programming', 'SEO', 'test', '3'],
                           ['2', 'Programming', 'SEO', 'test', '2'],
                           ['3', 'Programming', 'SEO', 'test', '3']],
          'recentlySubmittedChallenges' => [['1', 'Programming', 'SEO', 'test', 'test'],
                                            ['2', 'Programming', 'SEO', 'test', 'test'],
                                            ['3', 'Programming', 'SEO', 'test', 'test']],
      );
      return view('pages/index')->with($data);
    }

    public function submitNewScheme(){
      $data = array(
      );
      return view('pages/submitNewScheme')->with($data);
    }

    public function about(){
      $data = array(
          'title' => 'Services',
          'services' => ['Web Design', 'Programming', 'SEO']
      );
      return view('pages/about')->with($data);
    }
}
