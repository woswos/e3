<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

// Include the namespace from scheme and challenge for accesing to database
use App\Scheme;
use App\Challenge;
use App\Solution;

// Access all tables
use DB;

class ChallengesController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
      // Get all challenges from db
      $challenges = Challenge::orderBy('id', 'DESC')->get();

      // Not efficient at all but fastest way to do this for now
      // For counting submitted solutions per challenge
      $challenges_solution_counts = array();
      foreach ($challenges as $challenge) {
        // Count number of submitted solutions
        $solutions = Solution::where('challenge_id', $challenge->id)->get();
        $solution_count = $solutions->count();
        $challenges_solution_counts[$challenge->id] = $solution_count;
      }

      // Do some relational db stuff for counting submitted solutions per challenge
      //$solutions = DB::table('challenges')
      //                 ->join('solutions', 'solutions.challenge_id','=','challenges.id')
      //                 ->tosql();

      $data = array(
        'challenges' => $challenges,
        'challenges_solution_counts' => $challenges_solution_counts
        );

      return view('challenges/index')->with($data);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create($scheme_id = 0)
    {

        // If url was manually changed, redirect to challenge listing page
        if($scheme_id == 0){
          return redirect('challenge');
        } else {
          $scheme = Scheme::find($scheme_id);
          return view('challenges/create')->with('scheme', $scheme);
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
      // Check if all values are entered
      $this->validate($request, [
          'title' => 'required',
          'prize' => 'required',
          'explanation' => 'required',
          'scheme_id' => 'required',
          'attached_files' => 'nullable|max:50000'
      ]);

      // Handle File Upload
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
      $challenge = new Challenge;
      $challenge->scheme_id = $request->input('scheme_id');
      $challenge->title = $request->input('title');
      $challenge->prize = $request->input('prize');
      $challenge->explanation = $request->input('explanation');
      $challenge->difficulty = $request->input('difficulty');
      $challenge->attempts = 0;
      $challenge->solved = false;
      $challenge->attached_files = $fileNameToStore;
        // Update total prize of the corresponding scheme, before finalizing the query
        Scheme::where('id', $request->input('scheme_id'))->increment('total_prize', $request->input('prize'));
      $challenge->save();

      return redirect()->route('scheme.show', ['id' => $request->input('scheme_id')])->with('success', 'Challenge submitted successfully');

    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {

      //Find the scheme by id which is given in the url
      $challenge = Challenge::find($id);

      //Find the solutions by id which is given in the url
      $solutions = Solution::where('challenge_id', $id)->get();

      $data = array(
        'challenge' => $challenge,
        'solutions' => $solutions
        );

      return view('challenges/show')->with($data);
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
