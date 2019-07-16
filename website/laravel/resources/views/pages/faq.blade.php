@extends('layouts/app')

@section('content')
    <body data-spy="scroll"  data-target="#faq" data-offset="0">
        <section class="">
          <div class="container" id="faq">
            <h1>Frequently Asked Questions</h1>

            <div class="">
                <ul>
                    <div id="scheme">
                        <li><h5>Scheme Submission Instructions</h5></li>
                    </div>
                    <div id="benchmark">
                        <li><h5>Benchmark Submission Instructions</h5></li>
                    </div>
                    <div id="challenge">
                        <li><h5>Challenge Submission Instructions</h5></li>
                        <ul>
                            <div id="prize">
                                <li><h5>Prize</h5></li>
                                <ul>
                                    <li>Some text</li>
                                    <li>Some text</li>
                                </ul>
                            </div>

                            <div id="flag">
                                <li><h5>Flag</h5></li>
                                <ul>
                                    <li>Some text</li>
                                    <li>Some text</li>
                                </ul>
                            </div>
                        </ul>
                    </div>
                </ul>
            </div>

          </div>
        </section>
    </body>

@endsection
