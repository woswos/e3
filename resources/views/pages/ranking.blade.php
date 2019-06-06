@extends('layouts/app')

@section('content')
  <div class="container">
    <h1>Global Rankings</h1>
    <canvas id="ranking_chart" width="%100" height="100px" class="mt-4"></canvas>
    @include('partials/chart')
  </div>

@endsection
