@extends('layouts/app')

@section('content')
  <div class="container">
    <h3>{{ $scheme->title }}</h3>
    <h5 class="text-muted">{{ $scheme->authors }}</h5>
    <h5 class="text-muted">{{ $scheme->institutions }}</h5>
    <div>
        {{ $scheme->abstract }}
    </div>
    <br>
    <a href="{{ route('index') }}/storage/attached_files/{{ $scheme->attached_files }}" target="_blank">Download the paper [PDF]</a>
  </div>


  <div class="container mt-4">
    <h4>Available Challenges</h4>
    <h5><a href='{{ route('challenge.create') }}/{{ $scheme->id }}'>Create a challenge!</a></h5>

    @if(count($challenges) > 0)
        <ul class="list-group">
            @foreach($challenges as $challenge)
                <li class="list-group-item">
                  <a href="{{ route('challenge.index') }}/{{ $challenge->id }}" class="card-link">{{ $challenge->title }}</a>,
                  Prize: ${{ $challenge->prize }},
                  Total number of attempts: {{ $challenge->attempts }}
                </li>
            @endforeach
        </ul>
    @else
      <h6>No challenges are created</h6>
    @endif

  </div>

@endsection
