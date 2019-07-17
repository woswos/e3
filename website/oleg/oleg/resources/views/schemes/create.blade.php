@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
        <h1>Submit a new scheme</h1>
        <h6><i>Please download the example Cipherbit class located <a href="https://github.com/momalab/e3work/tree/master/tests/user/extern" target="_blank">here</a> and implement your own functions.</i></h6>
        <h6><i>Make sure that your code works before submitting any scheme</i></h6>

        {!! Form::open(['action' => 'SchemesController@store', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}

        <div class="form-group">
            {{Form::label('name', 'Your name')}}
            {{Form::text('name', '', ['class' => 'form-control'])}}
        </div>
        <div class="form-group">
            {{Form::label('email', 'Your email address')}}
            {{Form::text('email', '', ['class' => 'form-control'])}}
        </div>
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
    var yLabel = "";
    var xLabel = "";

    var data =
        [{
            label: '',
            data: [{ x: 0, y: 0 }],
            borderColor: '#ffffff',
            backgroundColor: '#ffffff',
            pointRadius: 4,
            pointHoverRadius: 4,
            cubicInterpolationMode: 'monotone'
        }];

    var ctx = document.getElementById("ranking_chart").getContext('2d');
    var config = {
        type: '{{ $chart_type }}',
        data: { datasets: data },
        options: {
                responsive: true,
                legend: { position: 'right' },
                scales: {
                        yAxes: [{ scaleLabel: { display: true, labelString: yLabel } }],
                        xAxes: [{ scaleLabel: { display: true, labelString: xLabel } }]
                        },

                tooltips: { callbacks: {
                                label: function(tooltipItem, data) {
                                        var label = data.labels[tooltipItem.index];
                                            @php
                                                 if($chart_mode == "index"){
                                                    echo "return label + ': (Total Prize: $' + tooltipItem.xLabel + ', Time: ' + tooltipItem.yLabel + ' us)';";
                                                } else if($chart_mode == "benchmark"){
                                                    echo "return label + ': (Operation: ' + tooltipItem.xLabel + ', Time: ' + tooltipItem.yLabel + ' us)';";
                                                }
                                            @endphp
                                        }
             }
          },
        }
    };

    var ranking_chart = new Chart(ctx, config);

    ////////////////////////////////////////////////////////////////////////////////

    function getRandomColor() {
        var colorArray = [
            '#3490dc',
            '#6574cd',
            '#9561e2',
            '#f66d9b',
            '#e3342f',
            '#f6993f',
            '#ffed4a',
            '#38c172',
            '#4dc0b5',
            '#6cb2eb',
            '#6c757d',
            '#343a40',
            '#3490dc',
            '#6c757d',
            '#38c172',
            '#6cb2eb',
            '#ffed4a',
            '#e3342f',
            '#343a40'
        ];

        return colorArray[Math.floor(Math.random()*colorArray.length)];
    }

    @php

        if($chart_mode == "index"){

            foreach ($chart_values as $key => $scheme) {

                echo "$(document).ready(function() {";
                    echo "var yLabel = '".ucfirst($key)." Time (us)';
                          var xLabel = 'Prize ($)';
                         ";

                    echo "var benchmark_data = [";
                        foreach ($scheme as $scheme_title => $speed_and_prize) {
                            echo "{";
                            echo "label: '".$scheme_title."',";
                            echo "data: [{ x: ".$speed_and_prize['prize']." , y: ".$speed_and_prize['speed']." }],";
                            echo "backgroundColor: getRandomColor(),";
                            echo "pointRadius: 4,";
                            echo "pointHoverRadius: 8,";
                            echo "cubicInterpolationMode: 'monotone'";
                            echo "},";
                        }

                    echo "];";


                    echo "
                          ranking_chart.config.data.datasets = benchmark_data;
                          ranking_chart.config.options.scales.yAxes[0].scaleLabel.labelString = yLabel;
                          ranking_chart.config.options.scales.xAxes[0].scaleLabel.labelString = xLabel;
                          ranking_chart.update();
                          });
                         ";
                         // Apply $(document).ready(function() for the first value only
                         break;
            }

            foreach ($chart_values as $key => $scheme) {

                echo " $('#".$key."').click(function() { ";
                    echo "var yLabel = '".ucfirst($key)." Time (us)';
                          var xLabel = 'Prize ($)';
                         ";

                    echo "var benchmark_data = [";
                        foreach ($scheme as $scheme_title => $speed_and_prize) {
                            echo "{";
                            echo "label: '".$scheme_title."',";
                            echo "data: [{ x: ".$speed_and_prize['prize']." , y: ".$speed_and_prize['speed']." }],";
                            echo "backgroundColor: getRandomColor(),";
                            echo "pointRadius: 4,";
                            echo "pointHoverRadius: 8,";
                            echo "cubicInterpolationMode: 'monotone'";
                            echo "},";
                        }

                    echo "];";


                    echo "
                          ranking_chart.config.data.datasets = benchmark_data;
                          ranking_chart.config.options.scales.yAxes[0].scaleLabel.labelString = yLabel;
                          ranking_chart.config.options.scales.xAxes[0].scaleLabel.labelString = xLabel;
                          ranking_chart.update();
                          });
                         ";
            }

        } else if($chart_mode == "benchmark"){

            echo "$(document).ready(function() {";
                echo "var yLabel = 'Time (us)';
                      var xLabel = 'Operation';
                     ";

                 echo " var chart_labels = [";
                         foreach ($chart_values['operation'] as $operation) {
                             echo "'".$operation."',";
                         }
                 echo "]; ";

                 echo "var benchmark_data = [";
                         foreach ($chart_values['speed'] as $speed) {
                             echo "'".$speed."',";
                         }
                 echo "]; ";

                echo "
                      ranking_chart.config.data.datasets[0].data = benchmark_data;
                      ranking_chart.config.data.datasets[0].borderColor = '#4169e1';
                      ranking_chart.config.data.datasets[0].backgroundColor = 'transparent';
                      ranking_chart.config.options.legend = false;
                      ranking_chart.config.data.labels = chart_labels;
                      ranking_chart.config.options.scales.yAxes[0].scaleLabel.labelString = yLabel;
                      ranking_chart.config.options.scales.xAxes[0].scaleLabel.labelString = xLabel;
                      ranking_chart.update();
                });
                 ";



        }

    @endphp

    </script>

@endsection
