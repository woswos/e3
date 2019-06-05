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
  <a class="btn btn-outline-secondary btn-lg" role="button" href='{{ route('submitNewScheme') }}'>Submit a scheme!</a>
  <a class="btn btn-outline-secondary btn-lg" role="button" >Break a scheme!</a>
</div>

<div class="container  mt-3">
  <div class="row">
    <div class="col-lg-6 col-md-6 col-sm-12">
      <h3>Total available prize: ${{ $totalPrizeAvailable }}</h3>
    </div>
    <div class="col-lg-6 col-md-6 col-sm-12">
      <h3>Total available challenges: {{ $totalPrizeChallenges }}</h3>
    </div>
  </div>
</div>

<div class="container">
  <div class="row">
    <div class="col-lg-6 col-md-6 col-sm-12">

      <table class="table">
        <thead>
          <tr>
            <th scope="col">#</th>
            <th scope="col">Name</th>
            <th scope="col">Institution</th>
            <th scope="col">Prize</th>
            <th scope="col">Attempts</th>
          </tr>
        </thead>
        <tbody>
          @if(count($topHackers) > 0)
            @foreach($topHackers as $hacker)
            <tr>
              <th scope="row">{{ $hacker[0] }}</th>
              <td>{{ $hacker[1] }}</td>
              <td>{{ $hacker[2] }}</td>
              <td>{{ $hacker[3] }}</td>
              <td>{{ $hacker[4] }}</td>
            </tr>
            @endforeach
          @endif
        </tbody>
      </table>


    </div>

    <div class="col-lg-6 col-md-6 col-sm-12">
      <div class="container">
        <table class="table">
          <thead>
            <tr>
              <th scope="col">#</th>
              <th scope="col">Name</th>
              <th scope="col">Institution</th>
              <th scope="col">Broken Challenges</th>
            </tr>
          </thead>
          <tbody>
            @if(count($topSchemes) > 0)
              @foreach($topSchemes as $scheme)
              <tr>
                <th scope="row">{{ $scheme[0] }}</th>
                <td>{{ $scheme[1] }}</td>
                <td>{{ $scheme[2] }}</td>
                <td>{{ $scheme[3] }}</td>
              </tr>
              @endforeach
            @endif
          </tbody>
        </table>

      </div>
    </div>
  </div>

  <div class="container">
    <h3>Recently submitted schemes</h3>
  </div>

  <div class="container">
    <div class="row mt-3 justify-content-center">
      @if(count($recentlySubmittedChallenges) > 0)
        @foreach($recentlySubmittedChallenges as $challenge)
          <div class="card card-custom mx-2 mb-3" style="width: 15rem;">
            <div class="card-body">
              <h5 class="card-title">{{ $challenge[0] }}</h5>
              <h6 class="card-subtitle mb-2 text-muted">{{ $challenge[1] }}</h6>
              <h6 class="card-subtitle mb-2 text-muted">{{ $challenge[2] }}</h6>
              <p class="card-text">{{ $challenge[3] }}</p>
              <a href="#" class="card-link">{{ $challenge[4] }}</a>
            </div>
          </div>
        @endforeach
      @endif
    </div>
  </div>

  @endsection
