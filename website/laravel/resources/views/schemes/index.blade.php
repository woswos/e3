@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
            <h1>Explore Encryption Schemes</h1>

            <h4><a href='{{ route('scheme.create') }}'>Submit a scheme!</a></h4>
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
