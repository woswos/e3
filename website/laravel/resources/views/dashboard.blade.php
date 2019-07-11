@extends('layouts.app')

@section('content')

    <div class="container">
        @if (session('status'))
            <div class="alert alert-success" role="alert">
                {{ session('status') }}
            </div>
        @endif
    </div>

    <section class="">
        <div class="container">
          <a class="btn btn-outline-primary btn-lg" role="button" href='{{ route('scheme.create') }}'>Submit another scheme!</a>
          <a class="btn btn-outline-primary btn-lg" role="button" href='{{ route('challenge.index') }}'>Break a scheme!</a>
          <a class="btn btn-outline-primary btn-lg" role="button" href='{{ route('benchmark.create') }}'>benchmark</a>
        </div>
    </section>

    <section class="mt-4">
        <div class="container">
            <h3>Schemes Submitted By You</h3>

            <table  class="table table-hover">
                @if(count($schemes) > 0)
                    @foreach($schemes as $scheme)
                        <tr scope="col">
                            <td scope="row" onclick="window.location='{{ route('scheme.index') }}/{{$scheme->id}}';" >
                                <div class="well">
                                    <div class="row mt-2">
                                        <div class="col-md col-sm">
                                            <h3><a href="{{ route('scheme.index') }}/{{$scheme->id}}">{{$scheme->title}}</a></h3>
                                            <h5>{{ $scheme->authors }}</h5>
                                            <h5>{{ $scheme->institutions }}</h5>
                                            <h6><a href="/scheme/{{$scheme->id}}/edit">Edit</a>&nbsp;/&nbsp;<a href="/benchmark/{{$scheme->id}}">Benchmark Results</a></h6>
                                            <small class="text-muted">Submitted on {{$scheme->created_at}}</small>
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
