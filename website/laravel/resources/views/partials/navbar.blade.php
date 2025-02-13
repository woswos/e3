<nav class="navbar navbar-expand-lg navbar-dark bg-dark fixed-top shadow-sm">
    <div class="container">
        <a class="navbar-brand" href="{{ url('/') }}">
            {{ config('app.name', 'Laravel') }}
        </a>
        <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="{{ __('Toggle navigation') }}">
            <span class="navbar-toggler-icon"></span>
        </button>

        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <!-- Left Side Of Navbar -->
            <ul class="navbar-nav mr-auto">

            <!--
            <li class="nav-item">
                <a class="nav-link" href="{{ route('index') }}">Home</a>
            </li>
            -->
            <li class="nav-item">
                <a class="nav-link {{ Request::is('scheme') ? 'active' : '' }}" href="{{ route('scheme.index') }}">Explore Encryption Schemes</a>
            </li>
            <li class="nav-item">
                <a class="nav-link {{ Request::is('challenge') ? 'active' : '' }}" href="{{ route('challenge.index') }}">Explore Challenges</a>
            </li>
            <li class="nav-item">
                <a class="nav-link {{ Request::is('ranking') ? 'active' : '' }}" href="{{ route('ranking') }}">Global Rankings</a>
            </li>
            <li class="nav-item">
                <a class="nav-link {{ Request::is('faq') ? 'active' : '' }}" href="{{ route('faq') }}">FAQ</a>
            </li>
            <li class="nav-item">
                <a class="nav-link {{ Request::is('about') ? 'active' : '' }}" href="{{ route('about') }}">About</a>
            </li>

            </ul>

            <!-- Right Side Of Navbar -->
            <ul class="navbar-nav ml-auto">
                <!-- Authentication Links -->
                @guest
                    <li class="nav-item">
                        <a class="nav-link {{ Request::is('login') ? 'active' : '' }}" href="{{ route('login') }}">{{ __('Login') }}</a>
                    </li>
                    @if (Route::has('register'))
                        <li class="nav-item">
                            <a class="nav-link {{ Request::is('register') ? 'active' : '' }}" href="{{ route('register') }}">{{ __('Register') }}</a>
                        </li>
                    @endif
                @else
                    <li class="nav-item">
                        <a class="nav-link {{ Request::is('dashboard') ? 'active' : '' }}" href="{{ route('dashboard') }}">{{ __('Dashboard') }}</a>
                    </li>
                    <li class="nav-item dropdown">
                        <a id="navbarDropdown" class="nav-link dropdown-toggle" href="#" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false" v-pre>
                            {{ Auth::user()->first_name }}&nbsp;{{ Auth::user()->last_name }} <span class="caret"></span>
                        </a>

                        <div class="dropdown-menu dropdown-menu-right" aria-labelledby="navbarDropdown">
                            <a class="dropdown-item" href="{{ route('scheme.create') }}">
                                {{ __('Submit Scheme') }}
                            </a>
                            <a class="dropdown-item" href="{{ route('challenge.index') }}">
                                {{ __('Break Scheme') }}
                            </a>
                            <a class="dropdown-item" href="{{ route('changepassword') }}">
                                {{ __('Change Password') }}
                            </a>
                            <div class="dropdown-divider"></div>
                            <a class="dropdown-item" href="{{ route('logout') }}"
                               onclick="event.preventDefault();
                                             document.getElementById('logout-form').submit();">
                                {{ __('Logout') }}
                            </a>

                            <form id="logout-form" action="{{ route('logout') }}" method="POST" style="display: none;">
                                @csrf
                            </form>
                        </div>
                    </li>
                @endguest
            </ul>
        </div>
    </div>
</nav>
