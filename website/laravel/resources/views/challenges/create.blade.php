@extends('layouts/app')

@section('content')
  <div class="container">
    <h1>Submit a new challenge</h1>
    <h5>Please submit ony one challenge per form</h5>
    <h6><i>Please review the <a href="{{ route('faq') }}#challenge" target="_blank">submission instructions</a> before submitting any challenge</i></h6>

    {!! Form::open(['action' => 'ChallengesController@store', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}

        <div class="form-group">
            {{Form::label('title', 'Title')}}
            {{Form::text('title', '', ['class' => 'form-control', 'placeholder' => 'Title'])}}
        </div>

        <div class="form-group">
            {{Form::label('prize', 'Prize')}}
            <h6><i>Please carefully review the <a href="{{ route('faq') }}#prize" target="_blank">instructions regarding the prize payment</a> before submitting a challenge with a monetary prize</i></h6>

            <div class="input-group">
                <div class="input-group-prepend">
                  <span class="input-group-text">$</span>
                </div>
                {{Form::number('prize', '', ['class' => 'form-control', 'placeholder' => 'Please enter without the dollar sign'])}}
            </div>
        </div>
        <div class="form-group">
            {{Form::label('difficulty', 'Pick a difficulty')}}
            {{Form::select("difficulty",['beginner' => 'Beginner', 'easy' => 'Easy', 'normal' => 'Normal', 'hard' => 'Hard', 'very_hard' => 'Very hard'], null, ["class" => "form-control"])}}
        </div>
        <div class="form-group">
            {{Form::label('explanation', 'Explanation')}}
            <h6>(LaTeX encoding is supported, check <a  href="{{ route('faq') }}#latex" target="_blank" >FAQ</a> for more information)</h6>
            {{Form::textarea('explanation', '', ['id' => 'article-ckeditor', 'class' => 'form-control', 'placeholder' => 'Please write your explanation here'])}}
        </div>
        <div class="form-group">
            {{Form::label('flag', 'Enter the secret key')}}
            <h6><i>You can review <a href="{{ route('faq') }}#flag" target="_blank">submission instructions</a> for more details about the secret key</i></h6>
            {{Form::text('flag', '', ['class' => 'form-control', 'placeholder' => 'Flag'])}}
        </div>
        <div class="form-group">
            {{Form::label('attached_files', 'Please attach the files here. Please only upload pdf or zip files: ')}}
            {{Form::file('attached_files', array('multiple'=>false,'class'=>'send-btn', 'accept' => '.pdf, .zip'))}}
        </div>
        <div class="form-group">
            {{Form::label('scheme_id', 'Right now you are submitting a challenge for "'.$scheme->title.'"')}}
            {{Form::hidden('scheme_id', $scheme->id, ['class' => 'form-control', 'placeholder' => $scheme->title])}}
        </div>
        {{Form::submit('Submit', ['class'=>'btn btn-primary'])}}

    {!! Form::close() !!}

  </div>

  <!--
  <div id='text1' style='display:none; '>Examletext</div>
  <script>
      $(document).ready(function() {
      $("#prize").keyup(function() {
           if($("#prize").val() > 100){
              if ($('#text1').is(":hidden")) {
                  $('#text1').show(500);
              } else {
                  $("#text1").hide(500);
              }
          }
       });
      });
  </script>
-->
@endsection
