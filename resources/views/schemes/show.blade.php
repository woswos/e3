@extends('layouts/app')

@section('content')
  <h1>{{$scheme->title}}</h1>
  <br><br>
  <div>
      {!!$scheme->abstract!!}
  </div>
@endsection
