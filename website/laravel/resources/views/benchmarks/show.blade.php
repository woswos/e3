@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
            <h3>{{ "dsfdsds" }}</h3>
            <h5 class="text-muted">{{ "dsfsd" }}</h5>
            <h5 class="text-muted">{{ "dsfdsds" }}</h5>
            <div>
                {{ "dsfdsds" }}
            </div>
            
            <br>

            <table style="width:100%;">
                <tr>
                    <td style="padding-left:10px; vertical-align: top">
                        <canvas id="ranking_chart" width="%100" height="105px"></canvas>
                        @include('partials/chart')
                    </td>
                </tr>
            </table>


        </div>
    </section>

@endsection
