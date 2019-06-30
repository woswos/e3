@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
            <h1>Explore Challenges</h1>

            <table  class="table table-hover">
                @if(count($challenges) > 0)
                    @foreach($challenges as $challenge)
                        <tr scope="col">
                            <td scope="row" onclick="window.location='{{ route('challenge.index') }}/{{$challenge->id}}';" >
                                <div class="well">
                                    <div class="row mt-2">
                                        <div class="col-md col-sm">
                                            <h3><a href="{{ route('challenge.index') }}/{{$challenge->id}}">{{$challenge->title}}</a></h3>
                                            <h5>
                                              Prize: ${{ $challenge->prize }},
                                              Difficulty: {{ ucfirst(str_replace('_', ' ', $challenge->difficulty)) }},
                                              Total attempts: {{ $challenge->attempts }},
                                              Submitted solutions: {{ $challenges_solution_counts[$challenge->id] }}
                                            </h5>
                                            <small class="text-muted">Submitted on {{$challenge->created_at}}</small>
                                        </div>
                                    </div>
                                </div>
                            </td>
                        </tr>
                    @endforeach
                @else
                    <p>No scheme submitted</p>
                @endif
            </table>
        </div>
    </section>
@endsection
