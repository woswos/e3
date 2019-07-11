@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
            <h3>{{ $scheme->title }}</h3>
            <h5 class="text-muted">{{ $scheme->authors }}</h5>
            <h4>Benchmark Results:</h4>

            <br>

            <table style="width:100%;">
                <tr>
                    <td style="padding-left:10px; vertical-align: top">
                        <canvas id="ranking_chart" width="%100" height="120px"></canvas>
                        @include('partials/chart')
                    </td>
                </tr>
            </table>


        </div>
    </section>

@endsection
