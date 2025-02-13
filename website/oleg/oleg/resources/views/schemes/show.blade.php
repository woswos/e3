@extends('layouts/app')

@section('content')
    <section class="">
      <div class="container">
        <h3 class="no-mathjax">{{ $scheme->title }}</h3>
        <h5 class="text-muted no-mathjax">{{ $scheme->authors }}</h5>
        <h5 class="text-muted no-mathjax">{{ $scheme->institutions }}</h5>
        <div class="mathjax">
            {{ $scheme->abstract }}
        </div>
        <br>
        @if ($scheme->keywords != "")
            <div class="no-mathjax">
                Keywords:
                @foreach(explode(",", $scheme->keywords) as $keyword)
                {{$keyword}}@if(!($loop->last)),&nbsp;@endif
                @endforeach
            </div>
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
                    @if($arithmetic == "sroot") @php $arithmetic="Square root"; @endphp @endif
                    {{ucfirst($arithmetic)}}@if(!($loop->last)),&nbsp;@endif
                    @endforeach
              </div>
            @endif
        @endforeach

        @foreach($implementation as $row)
            @if ($row->attached_files_implementation != "none")
              <a href="{{ route('index') }}/storage/attached_files_implementation/{{ $row->attached_files_implementation }}" target="_blank">Download code</a>
              <br>
            @endif
        @endforeach

        @foreach($implementation as $row)
            @if ($row->link != "none")
              <a href="{{ $row->link }}" target="_blank">Visit website</a>
            @endif
        @endforeach
      </div>
    </section>

    <section class="">
        <div class="container mt-4">
            <h4>Available Challenges</h4>

            @if(!Auth::guest())
                @if(Auth::user()->id == $scheme->user_id)
                    <h5><a href='{{ route('challenge.create') }}/{{ $scheme->id }}'>Click here to create a challenge!</a></h5>
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


    <section class="">
        <div class="container mt-4">
            <h4>Benchmark Results</h4>
            @if ($chart_values != "none")
                @if ($chart_values == "inQueue")
                    @if(!Auth::guest())
                        @if(Auth::user()->id == $scheme->user_id)
                            <h5>Your submission is waiting in the queue for processing</h5>
                        @endif
                    @else
                        <h6>This scheme doesn't have benchmark results yet</h6>
                    @endif
                @else
                    <table style="width:100%;">
                        <tr>
                            <td style="padding-left:10px; vertical-align: top">
                                <canvas id="ranking_chart" width="%100" height="105px"></canvas>
                                @include('partials/chart')
                            </td>
                        </tr>
                    </table>
                @endif
            @else
                @if(!Auth::guest())
                    @if(Auth::user()->id == $scheme->user_id)
                        <h5><a href='{{ route('benchmark.create') }}/{{ $scheme->id }}'>Click here to submit your scheme for benchmarking if you haven't already done so!</a></h5>
                    @endif
                @endif
                <h6>This scheme doesn't have benchmark results yet</h6>
            @endif
        </div>
    </section>


@endsection
