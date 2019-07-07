<script>
//var chart_labels = ['yarrak'];
//var benchmark_data = [{ x: 100, y: 200 }];

var chart_labels = [
    @foreach($schemes as $scheme)
       "{{ $scheme->title }}",
    @endforeach
];

var benchmark_data = [
    @foreach($schemes as $scheme)
     @if($scheme->speed != NULL)
       { x: {{ $scheme->total_prize }}, y: {{ $scheme->nand }} },
     @endif
    @endforeach
];

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
          pointHoverRadius: 8
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
              labelString: '32 Bit Integer Division Speed (ns)'
            }
          }],

          xAxes: [{
            scaleLabel: {
              display: true,
              labelString: 'Prize ($)'
            }
          }]
        },

        tooltips: {
         callbacks: {
            label: function(tooltipItem, data) {
               var label = data.labels[tooltipItem.index];
               return label + ': (Total Prize: $' + tooltipItem.xLabel + ', Speed: ' + tooltipItem.yLabel + ' ns)';
            }
         }
      },
    }
};

var ranking_chart = new Chart(ctx, config);


$("#and").click(function() {
    var chart_labels = [
        @foreach($schemes as $scheme)
           "{{ $scheme->title }}",
        @endforeach
    ];

    var benchmark_data = [
        @foreach($schemes as $scheme)
         @if($scheme->speed != NULL)
           { x: {{ $scheme->total_prize }}, y: {{ $scheme->nand }} },
         @endif
        @endforeach
    ];

    var data = ranking_chart.config.data;
    data.datasets[0].data = benchmark_data;
    data.labels = chart_labels;
    ranking_chart.update();
});


$("#not").click(function() {
    var chart_labels = ['test'];
    var benchmark_data = [{ x: 400, y: 800 }];

    var data = ranking_chart.config.data;
    data.datasets[0].data = benchmark_data;
    data.labels = chart_labels;
    ranking_chart.update();
});

$("#nand").click(function() {
    var chart_labels = ['test'];
    var benchmark_data = [{ x: 470, y: 870 }];

    var data = ranking_chart.config.data;
    data.datasets[0].data = benchmark_data;
    data.labels = chart_labels;
    ranking_chart.update();
});


$("#division_8").click(function() {
    var chart_labels = ['test'];
    var benchmark_data = [{ x: 100, y: 400 }];

    var data = ranking_chart.config.data;
    data.datasets[0].data = benchmark_data;
    data.labels = chart_labels;
    ranking_chart.update();
});


$("#division_32").click(function() {
    var chart_labels = ['test'];
    var benchmark_data = [{ x: 4000, y: 100 }];

    var data = ranking_chart.config.data;
    data.datasets[0].data = benchmark_data;
    data.labels = chart_labels;
    ranking_chart.update();
});

$("#or").click(function() {
    var chart_labels = ['test'];
    var benchmark_data = [{ x: 4000, y: 100 }];

    var data = ranking_chart.config.data;
    data.datasets[0].data = benchmark_data;
    data.labels = chart_labels;
    ranking_chart.update();
});

</script>
