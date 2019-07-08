@extends('layouts/app')

@section('content')
    <section class="">
      <div class="container">
        <h1>Global Rankings</h1>
    </div>
    <div class="container mt-3">
        <table style="width:100%;">
            <tr>
                <td style="vertical-align: top;">
                    <div class="list-group" id="graph_group">
                        @foreach ($chart_values as $key => $value)
                            <a href="javascript:;" id="{{ $key }}" class="list-group-item list-group-item-action @if(($loop->first)) active @endif">{{ucfirst( $key )}}</a>
                        @endforeach
                    </div>
                </td>
                <td style="padding-left:10px; vertical-align: top">
                    <canvas id="ranking_chart" width="%100" height="100px"></canvas>
                    @include('partials/chart')
                </td>
            </tr>
        </table>
      </div>
    </section>

    <script>
    // Get the container element
    var btnContainer = document.getElementById("graph_group");

    // Get all buttons with class="btn" inside the container
    var btns = btnContainer.getElementsByClassName("list-group-item");

    // Loop through the buttons and add the active class to the current/clicked button
    for (var i = 0; i < btns.length; i++) {
      btns[i].addEventListener("click", function() {
        var current = document.getElementsByClassName("active");
        current[0].className = current[0].className.replace(" active", "");
        this.className += " active";
      });
    }
    </script>

@endsection
