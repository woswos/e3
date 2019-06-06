<script>
  var ctx = document.getElementById('ranking_chart').getContext('2d');
  var myChart = new Chart(ctx, {
    type: 'scatter',
    data: {
      labels: [
        @foreach($schemes as $scheme)
           "{{ $scheme->title }}",
        @endforeach
      ],
       datasets: [{
          data: [
             @foreach($schemes as $scheme)
              @if($scheme->speed != NULL)
                { x: {{ $scheme->total_prize }}, y: {{ $scheme->speed }} },
              @endif
             @endforeach
          ],
          borderColor: '#3490dc',
          backgroundColor: '#3490dc',
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


    },

  });
</script>
