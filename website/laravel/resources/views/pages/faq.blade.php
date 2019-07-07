@extends('layouts/app')

@section('content')
    <body data-spy="scroll"  data-target="#faq" data-offset="0">
        <section class="">
          <div class="container" id="faq">
            <h1>Frequently Asked Questions</h1>

            <div class="">
                <ul>
                    <div id="submission">
                        <li><h5>Submission Instructions</h5></li>
                    </div>
                    <div id="prize">
                        <li><h5>Prize Payment Instructions</h5></li>
                        <ul>
                          <li>Phasellus iaculis neque</li>
                          <li>Purus sodales ultricies</li>
                          <li>Vestibulum laoreet porttitor sem</li>
                          <li>Ac tristique libero volutpat at</li>
                        </ul>
                    </div>
                </ul>
            </div>

          </div>
        </section>
    </body>

@endsection
