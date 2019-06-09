@extends('layouts/app')

@section('content')
  <div class="container">
    <h1>Explore Encryption Schemes</h1>

    <h4><a href='{{ route('scheme.create') }}'>Submit a scheme!</a></h4>

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

@endsection
