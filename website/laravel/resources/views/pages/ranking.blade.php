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
                    <div class="list-group" id="graph_group_">
                        @foreach ($chart_values as $key => $value)
                            <a href="javascript:;" id="{{ $key }}" class="list-group-item button_track list-group-item-action @if(($loop->first)) active @endif">{{ucfirst( $key )}}</a>
                        @endforeach
                    </div>
                </td>
                <td style="padding-left:10px; vertical-align: top">
                    <canvas id="ranking_chart" width="%100" height="205px"></canvas>
                    @include('partials/chart')
                </td>
            </tr>
        </table>
      </div>
    </section>

    <script>
    // Get the container element
    var btnContainer = document.getElementById("graph_group_");

    // Get all buttons with class="btn" inside the container
    var btns = btnContainer.getElementsByClassName("button_track");

    // Loop through the buttons and add the active class to the current/clicked button
    for (var i = 0; i < btns.length; i++) {
      btns[i].addEventListener("click", function() {
        var current = document.getElementsByClassName("list-group-item button_track list-group-item-action active");
        current[0].className = "list-group-item button_track list-group-item-action";
        this.className = "list-group-item button_track list-group-item-action active";
      });
    }
    </script>

@endsection
