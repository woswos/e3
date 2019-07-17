<script>
var chart_labels = [''];
var benchmark_data = [{ x: 0, y: 0 }];
var yLabel = "";
var xLabel = "";

var ctx = document.getElementById("ranking_chart").getContext('2d');
var config = {
    type: '{{ $chart_type }}',
    data: {
      labels: chart_labels,
       datasets: [{
          data: benchmark_data,
          borderColor: '#4169e1',
          @php
                if($chart_mode == "index"){
                  echo "backgroundColor: '#4169e1',";
                }
          @endphp
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

        legend: {
            position: 'right',
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

@php

    if($chart_mode == "index"){

        foreach ($chart_values as $key => $scheme) {

            echo "$(document).ready(function() {";
                echo "var yLabel = '".ucfirst($key)." Time (us)';
                      var xLabel = 'Prize ($)';
                     ";

                echo " var chart_labels = [";
                        foreach ($scheme as $scheme_title => $speed_and_prize) {
                            echo "'".$scheme_title."',";
                        }
                echo "]; ";

                echo "var benchmark_data = [";
                        foreach ($scheme as $scheme_title => $speed_and_prize) {
                            echo "{ x:".$speed_and_prize['prize']." , y:".$speed_and_prize['speed']." },";
                        }
                echo "]; ";

                echo "
                      ranking_chart.config.data.datasets[0].data = benchmark_data;
                      ranking_chart.config.data.labels = chart_labels;
                      ranking_chart.config.options.scales.yAxes[0].scaleLabel.labelString = yLabel;
                      ranking_chart.config.options.scales.xAxes[0].scaleLabel.labelString = xLabel;
                      ranking_chart.update();
                     ";
            echo "
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

                echo " var chart_labels = [";
                        foreach ($scheme as $scheme_title => $speed_and_prize) {
                            echo "'".$scheme_title."',";
                        }
                echo "]; ";

                echo "var benchmark_data = [";
                        foreach ($scheme as $scheme_title => $speed_and_prize) {
                            echo "{ x: ".$speed_and_prize['prize']." , y: ".$speed_and_prize['speed']." },";
                        }
                echo "]; ";

                echo "
                      ranking_chart.config.data.datasets[0].data = benchmark_data;
                      ranking_chart.config.data.labels = chart_labels;
                      ranking_chart.config.options.scales.yAxes[0].scaleLabel.labelString = yLabel;
                      ranking_chart.config.options.scales.xAxes[0].scaleLabel.labelString = xLabel;
                      ranking_chart.update();
                      });
                     ";
        }

    } else if($chart_mode == "benchmark"){

        $i = 0;

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
                  ranking_chart.config.data.labels = chart_labels;
                  ranking_chart.config.options.scales.yAxes[0].scaleLabel.labelString = yLabel;
                  ranking_chart.config.options.scales.xAxes[0].scaleLabel.labelString = xLabel;
                  ranking_chart.update();
            });
             ";



    }

@endphp

</script>
