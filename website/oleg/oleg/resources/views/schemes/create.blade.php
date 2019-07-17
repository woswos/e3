@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
        <h1>Submit a new scheme</h1>
        <h6><i>Please download the example Cipherbit class located <a href="https://github.com/momalab/e3work/tree/master/tests/user/extern" target="_blank">here</a> and implement your own functions.</i></h6>
        <h6><i>Make sure that your code works before submitting any scheme</i></h6>

        {!! Form::open(['action' => 'SchemesController@store', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}

            <!-- Attachments -->
            <div class="form-group">
                <h6>Please attach your scheme here. Zipping your code is recommended</h6>
                {{Form::file('attached_files', array('multiple'=>false,'class'=>'send-btn'))}}
            </div>

            <br>
            {{Form::submit('Submit', ['class'=>'btn btn-primary', "id" => "submit"])}}

        {!! Form::close() !!}
    </section>


    <section class="">
        <div class="container mt-5">
        <h1>Graph</h1>
        <canvas id="ranking_chart" width="%100" height="105px"></canvas>
    </section>



    <script>
    var chart_labels = [''];
    var benchmark_data = [{ x: 0, y: 0 }];
    var yLabel = "Time (us)";
    var xLabel = "Money";

    var ctx = document.getElementById("ranking_chart").getContext('2d');
    var config = {
        type: 'scatter',
        data: {
          labels: chart_labels,
           datasets: [{
              data: benchmark_data,
              borderColor: '#4169e1',
              backgroundColor: '#4169e1',
              pointRadius: 4,
              pointHoverRadius: 8,
              cubicInterpolationMode: 'monotone'
           }]
        },
        options: {
           responsive: true,
           legend: {
               display: false
            },

            scales: {
              yAxes: [{
                scaleLabel: {
                  display: true,
                  labelString: yLabel
                }
              }],

              xAxes: [{
                scaleLabel: {
                  display: true,
                  labelString: xLabel
                }
              }]
            },

            tooltips: {
             callbacks: {
                label: function(tooltipItem, data) {
                   var label = data.labels[tooltipItem.index];
                   return label + ': (Operation: ' + tooltipItem.xLabel + ', Time: ' + tooltipItem.yLabel + ' us)';
                }
             }
          },
        }
    };

    var ranking_chart = new Chart(ctx, config);

    </script>
@endsection
