@extends('layouts/app')

@section('content')
<div class="container">
  <div class="description">
    <h1>Welcome to the Obfuscation Wars!</h1>
    <p>
      <h4>Some catchy text</h4>
    </p>
  </div>
</div>

<div class="container">
  <a class="btn btn-outline-primary btn-lg" role="button" href='{{ route('scheme.create') }}'>Submit a scheme!</a>
  <a class="btn btn-outline-primary btn-lg" role="button" href='{{ route('challenge.index') }}'>Break a scheme!</a>
</div>

<div class="container  mt-5">
  <div class="row">
    <div class="col-lg-6 col-md-6 col-sm-12">
      <h3>Total unclaimed prize: $<span id="counter_1">{{ $totalPrizeAvailable }}</span></h3>
    </div>
    <div class="col-lg-6 col-md-6 col-sm-12">
      <h3>Total available challenges: <span id="counter_2">{{ $totalPrizeChallenges }}</span></h3>
    </div>
  </div>
</div>

<div class="container mt-5">
  <canvas id="ranking_chart" width="%100" height="100px" class="mt-4"></canvas>
  @include('partials/chart')
</div>

<div class="container mt-5">
  <div class="row">
    <div class="col-lg-6 col-md-6 col-sm-12">

      <!-- top schemes -->
      <table class="table">
        <thead>
          <tr>
            <th scope="col">#</th>
            <th scope="col">Scheme Title</th>
            <th scope="col">Institution</th>
            <th scope="col">Prize($)</th>
            <th scope="col">Attempts</th>
          </tr>
        </thead>
        <tbody>
          @if(count($topSchemes) > 0)
            @foreach($topSchemes as $scheme)
            <tr>
              <th scope="row">{{ $scheme->id }}</th>
              <td><a href="{{ route('scheme.index') }}/{{$scheme->id}}">{{$scheme->title}}</a></td>
              <td>{{ $scheme->institutions }}</td>
              <td>{{ $scheme->total_prize }}</td>
              <td>{{ $scheme->total_attempts }}</td>
            </tr>
            @endforeach
          @endif
        </tbody>
      </table>
    </div>


    <div class="col-lg-6 col-md-6 col-sm-12">
      <div class="container">

        <!-- top hackers -->
        <table class="table">
          <thead>
            <tr>
              <th scope="col">#</th>
              <th scope="col">Hacker Name</th>
              <th scope="col">Institution</th>
              <th scope="col">Broken Challenges</th>
            </tr>
          </thead>
          <tbody>
            @if(count($topHackers) > 0)
              @foreach($topHackers as $hacker)
              <tr>
                <th scope="row">{{ $hacker->id }}</th>
                <td>Test Name</td> <!-- name -->
                <td>0</td> <!-- Institution -->
                <td>0</td> <!-- Number of Broken Challenges -->
              </tr>
              @endforeach
            @endif
          </tbody>
        </table>

      </div>
    </div>
  </div>

  <div class="container mt-4">
    <h3>Recently submitted schemes</h3>
  </div>

  <div class="container">
    <div class="row mt-3 justify-content-center">
      @if(count($recentlySubmittedSchemes) > 0)
        @foreach($recentlySubmittedSchemes as $scheme)
          <div class="card card-custom mx-2 mb-3" style="width: 21rem;">
            <div class="card-body">
              <h5 class="card-title" href="#">{{ $scheme->title }}</h5>
              <h6 class="card-subtitle mb-2 text-muted">{{ $scheme->authors }}</h6>
              <h6 class="card-subtitle mb-2 text-muted">{{ $scheme->institutions }}</h6>
              <p class="card-text">{{ str_limit($scheme->abstract, $limit = 200, $end = '...') }}</p>
              <a href="{{ route('scheme.index') }}/{{ $scheme->id }}" class="card-link">Read more</a>
            </div>
          </div>
        @endforeach
      @endif
    </div>
  </div>

  <script type="text/javascript">
      const options = {
        duration: 3,
      };

      let counter_1 = new CountUp('counter_1', {{ $totalPrizeAvailable }}, options);
      let counter_2 = new CountUp('counter_2', {{ $totalPrizeChallenges }}, options);
      counter_1.start();
      counter_2.start();
  </script>

  @endsection
