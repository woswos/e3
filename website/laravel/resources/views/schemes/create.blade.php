@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
        <h1>Submit a new encryption scheme</h1>

        {!! Form::open(['action' => 'SchemesController@store', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}

            <div class="form-group">
                {{Form::label('title', 'Title')}}
                {{Form::text('title', '', ['class' => 'form-control', 'placeholder' => 'Title'])}}
            </div>
            <div class="form-group">
                {{Form::label('authors', 'Author(s)')}}
                {{Form::text('authors', '', ['class' => 'form-control', 'placeholder' => 'Please seperate each author with a comma (,)'])}}
            </div>
            <div class="form-group">
                {{Form::label('institutions', 'Institution(s)')}}
                {{Form::text('institutions', '', ['class' => 'form-control', 'placeholder' => 'Please seperate each institution with a comma (,)'])}}
            </div>
            <div class="form-group">
                {{Form::label('abstract', 'Abstract')}}
                {{Form::textarea('abstract', '', ['id' => '', 'class' => 'form-control', 'placeholder' => 'Please copy and paste your abstract here'])}}
            </div>
            <!-- Attachments -->
            <div class="form-group">
                {{Form::label('attached_files', 'Please attach the paper here. Please only upload pdf files: ')}}
                {{Form::file('attached_files', array('multiple'=>false,'class'=>'send-btn', 'accept' => '.pdf'))}}
            </div>
            <!-- Supported operations -->
            <div class="form-check">
                {!! Form::label('checkbox', 'Checkbox') !!}
                {!! Form::checkbox('checkbox') !!}
            </div>
            {{Form::submit('Submit', ['class'=>'btn btn-primary'])}}

        {!! Form::close() !!}

        </div>
    </section>
@endsection
