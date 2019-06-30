@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row justify-content-center">
        <!--<div class="col-md-12">
            <div class="card">
                <div class="card-header">Dashboard</div>

                <div class="card-body">-->
                    @if (session('status'))
                        <div class="alert alert-success" role="alert">
                            {{ session('status') }}
                        </div>
                    @endif


                    <div class="container">
                      <a class="btn btn-outline-primary btn-lg" role="button" href='{{ route('scheme.create') }}'>Submit a scheme!</a>
                      <a class="btn btn-outline-primary btn-lg" role="button" href='{{ route('challenge.index') }}'>Break a scheme!</a>
                    </div>


                    <div class="container">
                    <h3>Schemes Submitted By You</h3>
                    @if(count($schemes) > 0)
                        @foreach($schemes as $scheme)
                            <div class="well">
                                <div class="row mt-4">
                                    <div class="col-md col-sm">
                                        <h3><a href="{{ route('scheme.index') }}/{{$scheme->id}}">{{$scheme->title}}</a></h3>
                                        <h5>{{ $scheme->authors }}</h5>
                                        <h5>{{ $scheme->institutions }}</h5>
                                        <small class="text-muted">Submitted on {{$scheme->created_at}}</small>
                                    </div>
                                </div>
                            </div>
                        @endforeach
                    @else
                        <p>No scheme submitted</p>
                    @endif
                </div>
<!--
                </div>
            </div>
        </div>-->
    </div>
</div>
@endsection
