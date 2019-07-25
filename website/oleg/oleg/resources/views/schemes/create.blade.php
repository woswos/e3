@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
            <div class="row">
              <div class="col-sm-6">
                  <h1>Submit a new scheme</h1>
                  <h6><i>If you developed a new homomorphic encryption scheme, please submit your HE scheme here</i></h6>
                  <h6>Please download the example Cipherbit class located <a href="https://github.com/momalab/e3work/tree/master/tests/user/extern" target="_blank">here</a> and implement your own gate functions</h6>
                  <h6>Make sure that your code works before submitting any scheme</h6>

                  {!! Form::open(['action' => 'SchemesController@store', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}

                  <div class="form-group">
                      {{Form::label('name', 'Your name:')}}
                      {{Form::text('name', '', ['class' => 'form-control'])}}
                  </div>
                  <div class="form-group">
                      {{Form::label('email', 'Your email address:')}}
                      {{Form::text('email', '', ['class' => 'form-control'])}}
                  </div>
                  <!-- Attachments -->
                  <div class="form-group">
                      <h6>Please attach your scheme here. Zipping your code is recommended</h6>
                      {{Form::file('attached_files', array('multiple'=>false,'class'=>'send-btn'))}}
                  </div>

                  {{Form::submit('Submit', ['class'=>'btn btn-primary', "id" => "submit"])}}

                  {!! Form::close() !!}
              </div>

            <div class="col-sm-6">
                <h1>Submit a solution</h1>
                <h6><i>If you broke a scheme, please submit your explanation here</i></h6>
                <h6>The secret string that you broke is the password for the submission, you cannot submit your explanation
                    without figuring out the password</h6>
                {!! Form::open(['action' => 'SchemesController@solutionStore', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}

                <div class="form-group">
                    {{Form::label('scheme_id', 'Select encryption scheme that you broke:')}}
                    @php
                        $options = array();
                        $selected = 1;
                    @endphp
                    @foreach ($benchmarks as $benchmark)
                        @php
                        $options[$benchmark->id] = $benchmark->name;
                        @endphp
                    @endforeach
                    {!! Form::select('scheme_id', $options, $selected, array('class' => 'form-control')) !!}
                </div>
                <div class="form-group">
                    {{Form::label('name', 'Your name:')}}
                    {{Form::text('name', '', ['class' => 'form-control'])}}
                </div>
                <div class="form-group">
                    {{Form::label('email', 'Your email address:')}}
                    {{Form::text('email', '', ['class' => 'form-control'])}}
                </div>
                <!-- Attachments -->
                <div class="form-group">
                    <h6>Please attach your explanation here. Zipping your code/explanation is recommended</h6>
                    {{Form::file('attached_files', array('multiple'=>false,'class'=>'send-btn'))}}
                </div>

                <div class="form-group">
                    {{Form::label('secret_string', 'Secret string (password):')}}
                    {{Form::text('secret_string', '', ['class' => 'form-control'])}}
                </div>

                {{Form::submit('Submit', ['class'=>'btn btn-primary', "id" => "submit"])}}

                {!! Form::close() !!}
            </div>
        </div>
    </div>
    </section>



    <section class="">
        <div class="container mt-5">
        <h1>Previously Submitted HE Schemes</h1>
        <h5>Click <a href="https://github.com/momalab/e3work/tree/master/tests/user/extern" target="_blank">here</a> download the example gate API implementation</h5>
        <br>
        @foreach ($benchmarks as $benchmark)

            <h5><i>Name:</i> {{ $benchmark->name }}</h5>
            <h5><i>Email:</i> {{ $benchmark->email }}</h5>
            <h5><i>Benchmark results:</i></h5>
            <h5>Click <a href="{{ route('index') }}/storage/obw_pack/{{ $benchmark->obw_pack }}" target="_blank">here</a> download submitted gate API implementation and the challenge</h5>

            @if ($benchmarks_charts[$benchmark->id] != "none")
                <canvas id="ranking_chart_{{ $benchmark->id }}" width="%100" class="mt-3" height="125px"></canvas>
            @else
                <h5>Submitted gate API is waiting to be benchmarked</h5>
            @endif
            <hr>




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

    var ctx = document.getElementById("ranking_chart_{{ $benchmark->id }}").getContext('2d');
    var config = {
        type: '{{ $chart_type }}',
        data: { datasets: data },
        options: {
                responsive: true,
                legend: { position: 'right' },
                scales: {
                        yAxes: [{ type: 'logarithmic', scaleLabel: { display: true, labelString: yLabel } }],
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

    var ranking_chart_{{ $benchmark->id }} = new Chart(ctx, config);

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

        if($chart_mode == "benchmark" and $benchmarks_charts[$benchmark->id] != "none"){

            echo "$(document).ready(function() {";
                echo "var yLabel = 'Time (us)';
                      var xLabel = 'Operation';
                     ";

                 echo " var chart_labels = [";
                         foreach ($benchmarks_charts[$benchmark->id]['operation'] as $operation) {
                             echo "'".$operation."',";
                         }
                 echo "]; ";

                 echo "var benchmark_data = [";
                         foreach ($benchmarks_charts[$benchmark->id]['speed'] as $speed) {
                             echo "'".$speed."',";
                         }
                 echo "]; ";

                echo "
                      ranking_chart_$benchmark->id.config.data.datasets[0].data = benchmark_data;
                      ranking_chart_$benchmark->id.config.data.datasets[0].borderColor = '#4169e1';
                      ranking_chart_$benchmark->id.config.data.datasets[0].backgroundColor = 'transparent';
                      ranking_chart_$benchmark->id.config.options.legend = false;
                      ranking_chart_$benchmark->id.config.data.labels = chart_labels;
                      ranking_chart_$benchmark->id.config.options.scales.yAxes[0].scaleLabel.labelString = yLabel;
                      ranking_chart_$benchmark->id.config.options.scales.xAxes[0].scaleLabel.labelString = xLabel;
                      ranking_chart_$benchmark->id.update();
                });
                 ";



        }

    @endphp

    </script>

@endforeach
</section>

@endsection
