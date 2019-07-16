@extends('layouts/app')

@section('content')
    <body data-spy="scroll"  data-target="#faq" data-offset="0">
        <section class="">
          <div class="container" id="faq">
            <h1>Frequently Asked Questions</h1>

            <div class="no-mathjax">
                <ul>
                    <div id="oleg">
                        <li><h5>Full scenerio for Oleg</h5></li>
                        <ul>
                            <li>1 - Researcher visits the website</li>
                            <li>2 - Creates an account</li>
                            <li>3a - Reads instructions for the submission</li>
                            <li>3b - Downloads the benchmark package (I mean cipherbit files)</li>
                            <li>3c - Implements their scheme using the cipherbit class</li>

                            <li>4 - Researcher submits the paper explaining the theory behind the scheme by clicking submit a scheme button. Researcher can also add example code for informing public about real case scenarios, usability demonstration, etc</li>
                            <li>5 - Researcher submits the implemented code for benchmarking by clicking submit implementation for benchmarking button</li>
                            <li>6 - Benchmark server checks the submission queue and downloads the zip and runs the test</li>
                            <li>7 - Benchmark server uploads the results to webserver</li>
                            <li>8 - Results are publicly displayed</li>

                            <li>9 - In the meantime, researcher creates challenges under submitted schemes by using create a challenge buttons. Researchers gives the challenge a title, prize amount, and a secret value that attackers need to find.</li>
                            <li>10 - These challenges are displayed under schemes for other people to break</li>
                            <li>11 - Similarly, attackers create accounts on the website for submitting the solutions</li>
                            <li>12 - Attackers submit their solution way and the secret value to the website</li>
                            <li>13 - If secret values match, they receive their award and their solutions are publicly displayed under the corresponding challenges</li>
                        </ul>
                    </div>
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
                    <div id="latex">
                        <li><h5>Information about using LaTeX within the website</h5></li>
                        <ul>
                            <li>
                                <a href="https://www.mathjax.org/" target="_blank">MathJax</a> JavaScript library is used for providing the LaTeX support. LaTeX formatting is only allowed in long text fields like
                                abstracts, challenge and solution explanations. LaTeX formatting is not supported for short text inputs like titles, author
                                names, and institution names.
                            </li>
                            <li>
                                For inline formulas, enclose the formula in $...$. For displayed formulas, use $$...$$.
                            <li>
                                You can find a detailed tutorial about using MathJax
                                <a href="https://math.meta.stackexchange.com/questions/5020/mathjax-basic-tutorial-and-quick-reference" target="_blank">here</a>.
                            </li>
                        </ul>
                    </div>
                </ul>
            </div>

          </div>
        </section>
    </body>

@endsection
