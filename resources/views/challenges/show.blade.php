@extends('layouts/app')

@section('content')
  <div class="container">
    <h3>{{ $challenge->title }}</h3>
    <h5 class="text-muted">Prize: ${{ $challenge->prize }}</h5>
    <h5 class="text-muted">Difficulty: {{ ucfirst(str_replace('_', ' ', $challenge->difficulty)) }}</h5>
    <h5 class="text-muted">Total attempts: {{ $challenge->attempts }}</h5>
    <div>
        {!! $challenge->explanation !!}
    </div>
    <br>

    @if ($challenge->attached_files != "none")
      <a href="{{ route('index') }}/storage/attached_files/{{ $challenge->attached_files }}" target="_blank">Download attached files</a>
    @endif
  </div>

  <div class="container mt-4">
    <h4>Submitted Solutions</h4>
    <h5><a href='{{ route('solution.create') }}/{{ $challenge->id }}'>Submit a solution!</a></h5>
    
    @if(count($solutions) > 0)

        <ul class="list-group">
            @foreach($solutions as $solution)
                <a href="{{ route('solution.index') }}/{{ $solution->id }}" class="link">
                  <li class="list-group-item mt-1">
                    {{ $solution->title }}
                  </li>
                </a>
            @endforeach
        </ul>
    @else
      <h6>No solutions are submitted</h6>
    @endif

  </div>

@endsection
