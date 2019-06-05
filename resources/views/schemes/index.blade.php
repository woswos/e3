@extends('layouts/app')

@section('content')
    <h1>Posts</h1>
    @if(count($schemes) > 0)
        @foreach($schemes as $scheme)
            <div class="well">
                <div class="row">
                    <div class="col-md-8 col-sm-8">
                        <h3><a href="{{ route('scheme.index') }}/{{$scheme->id}}">{{$scheme->title}}</a></h3>
                        <small>Written on {{$scheme->created_at}}</small>
                    </div>
                </div>
            </div>
        @endforeach
    @else
        <p>No posts found</p>
    @endif
@endsection
