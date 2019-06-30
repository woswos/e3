<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

// Include the namespace from scheme and challenge for accesing to database
use App\Scheme;
use App\Challenge;
use App\Solution;

class SolutionsController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        return redirect()->route('index');
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create($challenge_id = 0)
    {
        // If url was manually added, redirect to challenge listing page
        if($challenge_id == 0){
          return redirect('challenge');
        } else {
          $challenge = Challenge::find($challenge_id);
          $scheme = Scheme::find($challenge->scheme_id);

          $data = array(
            'challenge' => $challenge,
            'scheme' => $scheme
          );

          return view('solutions/create')->with($data);
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
          'explanation' => 'required',
          'scheme_id' => 'required',
          'challenge_id' => 'required',
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

      // Create a solution
      $solution = new Solution;
      $solution->scheme_id = $request->input('scheme_id');
      $solution->challenge_id = $request->input('challenge_id');
      $solution->title = $request->input('title');
      $solution->explanation = $request->input('explanation');
      $solution->attached_files = $fileNameToStore;
      $solution->user_id = auth()->user()->id;
      $solution->save();

      return redirect()->route('challenge.show', ['id' => $request->input('challenge_id')])->with('success', 'Solution Submitted');

    }

    /**
     * Increase number of attempts counter
     * then redirect to the destination
     */
    public function attempt($destination, $parameter)
    {
      //Find the scheme by id which is given in the url
      //$solution = Solution::find($id);

      // DOESN'T WORK RIGHT NOW
      if($destination == "create"){
        return route('challenge.create', $parameter);
      } elseif ($destination == "download") {
        return redirect()->route('challenge.create', $parameter);
      } else {
        return redirect()->route('index');
      }


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
      $solution = Solution::find($id);

      $data = array(
        'solution' => $solution
        );

      return view('solutions/show')->with($data);
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
