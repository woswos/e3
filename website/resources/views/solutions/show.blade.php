@extends('layouts/app')

@section('content')
  <div class="container">
    <h3>{{ $solution->title }}</h3>
    <div>
        {!! $solution->explanation !!}
    </div>
    <br>

    @if ($solution->attached_files != "none")
      <a href="{{ route('index') }}/storage/attached_files/{{ $solution->attached_files }}" target="_blank">Download attached files</a>
    @endif
  </div>

@endsection
