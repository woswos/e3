@extends('layouts/app')

@section('content')
    <section class="">
      <div class="container">
        <h3>{{ $scheme->title }}</h3>
        <h5 class="text-muted">{{ $scheme->authors }}</h5>
        <h5 class="text-muted">{{ $scheme->institutions }}</h5>
        <div>
            {{ $scheme->abstract }}
        </div>
        <br>
        @if ($scheme->keywords != "")
            <div>
                Keywords:
                @foreach(explode(",", $scheme->keywords) as $keyword)
                {{$keyword}}@if(!($loop->last)),&nbsp;@endif
                @endforeach
            </div>
            <br>
        @endif

        @if ($scheme->attached_files != "none")
          <a href="{{ route('index') }}/storage/attached_files/{{ $scheme->attached_files }}" target="_blank">Download corresponding paper</a>
        @endif
      </div>
      <br>
      <div class="container">
        <h4>Software Implementation</h4>
        @foreach($implementation as $row)
          <div>
                Implemented in:
                @if ($row->programming_language != "Other")
                    {{$row->programming_language}}
                @else
                    {{$row->programming_language_other}}
                @endif
          </div>
        @endforeach
        @foreach($implementation as $row)
            @if ($row->gate != "")
              <div>
                    Natively supported gate operations:
                    @foreach(explode(",", $row->gate) as $gate)
                    {{ucfirst($gate)}}@if(!($loop->last)),&nbsp;@endif
                    @endforeach
              </div>
            @endif
        @endforeach
        @foreach($implementation as $row)
            @if ($row->arithmetic != "")
              <div>
                    Natively supported arithmetic operations:
                    @foreach(explode(",", $row->arithmetic) as $arithmetic)
                    {{ucfirst($arithmetic)}}@if(!($loop->last)),&nbsp;@endif
                    @endforeach
              </div>
            @endif
        @endforeach

        @foreach($implementation as $row)
            @if ($row->attached_files_implementation != "none")
              <a href="{{ route('index') }}/storage/attached_files/{{ $row->attached_files_implementation }}" target="_blank">Download code</a>
            @endif
        @endforeach
      </div>
    </section>

    <section class="">
        <div class="container mt-4">
            <h4>Available Challenges</h4>

            @if(!Auth::guest())
                @if(Auth::user()->id == $scheme->user_id)
                    <h5><a href='{{ route('challenge.create') }}/{{ $scheme->id }}'>Create a challenge!</a></h5>
                @endif
            @endif

            @if(count($challenges) > 0)

                <ul class="list-group">
                    @foreach($challenges as $challenge)
                        <a href="{{ route('challenge.index') }}/{{ $challenge->id }}" class="link">
                          <li class="list-group-item mt-1">
                            {{ $challenge->title }},
                            Difficulty: {{ ucfirst(str_replace('_', ' ', $challenge->difficulty)) }},
                            Prize: ${{ $challenge->prize }},
                            Total number of attempts: {{ $challenge->attempts }}
                          </li>
                        </a>
                    @endforeach
                </ul>
            @else
              <h6>No challenges are created</h6>
            @endif

        </div>
    </section>

@endsection
