<!DOCTYPE html>
<html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <!-- CSRF Token -->
    <meta name="csrf-token" content="{{ csrf_token() }}">

    <title>{{ config('app.name', 'Laravel') }}</title>

    <!-- Fonts -->
    <link rel="dns-prefetch" href="//fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css?family=Nunito" rel="stylesheet">

    <!-- Styles -->
    <link href="{{ asset('css/app.css') }}" rel="stylesheet">
    <link href="{{ asset('css/custom.css') }}" rel="stylesheet">

    <!-- Scripts -->
    <script src="{{ asset('js/app.js') }}" defer></script>

    <!-- chart.js script, needs to be loaded before the chart -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.8.0/Chart.bundle.min.js"></script>

    <!-- Text editor script -->
    <script src="/vendor/unisharp/laravel-ckeditor/ckeditor.js"></script>

    <!-- Stat counter script -->
    <script src="{{ asset('js/countUp.js') }}"></script>

</head>
<body>
    <!--<div id="app">-->
        @include('partials/navbar')

        <div class="container py-4">
            @include('partials/messages')
            @yield('content')
            @include('partials/footer')
        </div>

        <script>
            CKEDITOR.replace( 'article-ckeditor' );
        </script>
    <!--</div>-->
</body>
</html>
