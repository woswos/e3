<script>
var yLabel = "y";
var xLabel = "x";



var data1 =
    {
        label: 'test1',
        data: [{ x: 0, y: 0 }],
        borderColor: '#000000',
        backgroundColor: '#000000',
        pointRadius: 4,
        pointHoverRadius: 8,
        cubicInterpolationMode: 'monotone'
    };


var data2 =
    {
        label: 'test2',
        data: [{ x: 10, y: 10 }],
        borderColor: '#4169e1',
        backgroundColor: '#4169e1',
        pointRadius: 4,
        pointHoverRadius: 8,
        cubicInterpolationMode: 'monotone'
    };


var data = [data1, data2];


var ctx = document.getElementById("ranking_chart").getContext('2d');
var config = {
    type: '{{ $chart_type }}',
    data: { datasets: data },
    options: { responsive: true, legend: { position: 'right' },
            scales: {
                    yAxes: [{ scaleLabel: { display: true, labelString: yLabel } }],
                    xAxes: [{ scaleLabel: { display: true, labelString: xLabel } }]
                    },

            tooltips: { callbacks: {
                                    label: function(tooltipItem, data) {
                                                                        var label = data.labels[tooltipItem.index];
                                                                        return label + ': (Total Prize: $' + tooltipItem.xLabel + ', Time: ' + tooltipItem.yLabel + ' us)';
                                                                        }
         }
      },
    }
};

var ranking_chart = new Chart(ctx, config);

////////////////////////////////////////////////////////////////////////////////

</script>
