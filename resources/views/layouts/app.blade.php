<!doctype html>
<html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">

        <title>{{ config('app.name') }}</title>

        <link  rel="icon" type="image/x-icon"  href="data:image/svg+xml;utf8;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iaXNvLTg4NTktMSI/Pgo8IS0tIEdlbmVyYXRvcjogQWRvYmUgSWxsdXN0cmF0b3IgMTkuMC4wLCBTVkcgRXhwb3J0IFBsdWctSW4gLiBTVkcgVmVyc2lvbjogNi4wMCBCdWlsZCAwKSAgLS0+CjxzdmcgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiB4bWxuczp4bGluaz0iaHR0cDovL3d3dy53My5vcmcvMTk5OS94bGluayIgdmVyc2lvbj0iMS4xIiBpZD0iQ2FwYV8xIiB4PSIwcHgiIHk9IjBweCIgdmlld0JveD0iMCAwIDUxMiA1MTIiIHN0eWxlPSJlbmFibGUtYmFja2dyb3VuZDpuZXcgMCAwIDUxMiA1MTI7IiB4bWw6c3BhY2U9InByZXNlcnZlIiB3aWR0aD0iNTEycHgiIGhlaWdodD0iNTEycHgiPgo8Zz4KCTxnPgoJCTxwYXRoIGQ9Ik01MTIsMTQ1LjMxMXYtMzBoLTQzLjY2NlY4Mi40NTRsLTM4Ljc4Ny0zOC43ODdoLTMyLjg1OFYwaC0zMHY0My42NjdoLTUzLjc5MlYwaC0zMHY0My42NjdoLTUzLjc5MlYwaC0zMHY0My42NjdoLTUzLjc5MiAgICBWMGgtMzB2NDMuNjY3SDgyLjQ1NEw0My42NjcsODIuNDU0djMyLjg1OEgwdjMwaDQzLjY2N3Y1My43OTJIMHYzMGg0My42Njd2NTMuNzkzSDB2MzBoNDMuNjY3djUzLjc5MkgwdjMwaDQzLjY2N3YzMi44NTggICAgbDM4Ljc4NywzOC43ODdoMzIuODU4VjUxMmgzMHYtNDMuNjY3aDUzLjc5MlY1MTJoMzB2LTQzLjY2N2g1My43OTJWNTEyaDMwdi00My42NjdoNTMuNzkyVjUxMmgzMHYtNDMuNjY3aDMyLjg1OGwzOC43ODctMzguNzg3ICAgIHYtMzIuODU4SDUxMnYtMzBoLTQzLjY2NnYtNTMuNzkySDUxMnYtMzBoLTQzLjY2NnYtNTMuNzkzSDUxMnYtMzBoLTQzLjY2NnYtNTMuNzkySDUxMnogTTQzOC4zMzQsNDE3LjEybC0yMS4yMTMsMjEuMjEzSDk0Ljg4ICAgIEw3My42NjcsNDE3LjEyVjk0Ljg4TDk0Ljg4LDczLjY2N2gzMjIuMjQxbDIxLjIxMywyMS4yMTNWNDE3LjEyeiIgZmlsbD0iIzAwMDAwMCIvPgoJPC9nPgo8L2c+CjxnPgoJPGc+CgkJPHBhdGggZD0iTTMyNi4zOTIsMjQzLjgyM3YtMzkuMDk3aDAuMDAxYzAtMzguODE0LTMxLjU3OC03MC4zOTMtNzAuMzkzLTcwLjM5M2MtMzguODE0LDAtNzAuMzkzLDMxLjU3OC03MC4zOTMsNzAuMzkzdjM5LjA5NyAgICBoLTMwLjEwNHYxMjIuNTI2aDIwMC45OTNWMjQzLjgyM0gzMjYuMzkyeiBNMjU2LDE2NC4zMzNjMjIuMjczLDAsNDAuMzkzLDE4LjEyLDQwLjM5Myw0MC4zOTN2MzkuMDk3aC04MC43ODV2LTM5LjA5N2gtMC4wMDEgICAgQzIxNS42MDcsMTgyLjQ1MywyMzMuNzI3LDE2NC4zMzMsMjU2LDE2NC4zMzN6IE0zMjYuNDk3LDMzNi4zNDlIMTg1LjUwNHYtNjIuNTI2SDI0MXYzMC43MzFoMzB2LTMwLjczMWg1NS40OTdWMzM2LjM0OXoiIGZpbGw9IiMwMDAwMDAiLz4KCTwvZz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8Zz4KPC9nPgo8L3N2Zz4K"/>

        <link href="{{ asset('css/app.css') }}" rel="stylesheet">
        <link href="{{ asset('css/custom.css') }}" rel="stylesheet">
    </head>
    <body>
        <div class="container">
          @include('partials/navbar')
          @include('partials/messages')
          @yield('content')
          @include('partials/footer')
        </div>

        <script src="/vendor/unisharp/laravel-ckeditor/ckeditor.js"></script>
        <script>
            CKEDITOR.replace( 'article-ckeditor' );
        </script>
    </body>
</html>
