@extends('layouts/app')

@section('content')
  <div class="container">
    <h1>Submit a new solution</h1>
    <h5>Please submit ony one solution per form</h5>

    {!! Form::open(['action' => 'SolutionsController@store', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}

        <div class="form-group">
            {{Form::label('title', 'Title')}}
            {{Form::text('title', '', ['class' => 'form-control', 'placeholder' => 'Please give your solution a title'])}}
        </div>
        <div class="form-group">
            {{Form::label('explanation', 'Explanation')}}
            {{Form::textarea('explanation', '', ['id' => 'article-ckeditor', 'class' => 'form-control', 'placeholder' => 'Please copy and paste your abstract here'])}}
        </div>
        <div class="form-group">
            {{Form::label('flag', 'Enter the secret key')}}
            {{Form::text('flag', '', ['class' => 'form-control', 'placeholder' => 'Flag'])}}
        </div>
        <div class="form-group">
            {{Form::label('attached_files', 'Please attach the files here. Please only upload pdf or zip files: ')}}
            {{Form::file('attached_files', array('multiple'=>false,'class'=>'send-btn', 'accept' => '.pdf, .zip'))}}
        </div>
        <div class="form-group">
            {{Form::label('scheme_id', 'Right now you are submitting a solution for "'.$challenge->title.'" challenge under "'.$scheme->title.'" encryption scheme')}}
            {{Form::hidden('scheme_id', $scheme->id, ['class' => 'form-control', 'placeholder' => $scheme->title])}}
            {{Form::hidden('challenge_id', $challenge->id, ['class' => 'form-control', 'placeholder' => $challenge->title])}}
        </div>
        {{Form::submit('Submit', ['class'=>'btn btn-primary'])}}

    {!! Form::close() !!}

  </div>
@endsection
