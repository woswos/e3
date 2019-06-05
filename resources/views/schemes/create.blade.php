@extends('layouts/app')

@section('content')
    <h1>Create Posts</h1>

    {!! Form::open(['action' => 'SchemesController@store', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}
        <div class="form-group">
            {{Form::label('title', 'Title')}}
            {{Form::text('title', '', ['class' => 'form-control', 'placeholder' => 'Title'])}}
        </div>
        <div class="form-group">
            {{Form::label('authors', 'authors')}}
            {{Form::text('authors', '', ['class' => 'form-control', 'placeholder' => 'authors'])}}
        </div>
        <div class="form-group">
            {{Form::label('abstract', 'abstract')}}
            {{Form::textarea('abstract', '', ['id' => '', 'class' => 'form-control', 'placeholder' => 'abstract Text'])}}
        </div>
        <div class="form-group">
            {!! Form::file('attached_files', array('multiple'=>true,'class'=>'send-btn')) !!}
        </div>
        {{Form::submit('Submit', ['class'=>'btn btn-primary'])}}
    {!! Form::close() !!}

@endsection
