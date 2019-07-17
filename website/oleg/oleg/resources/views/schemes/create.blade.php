@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
        <h1>Submit a new encryption scheme</h1>
        <h6><i>Please review the <a href="{{ route('faq') }}#scheme" target="_blank">submission instructions</a> before submitting any scheme</i></h6>

        {!! Form::open(['action' => 'SchemesController@store', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}
            <h3>Part 1: Theory</h3>
            <div class="form-group">
                {{Form::label('title', 'Title')}}
                {{Form::text('title', '', ['class' => 'form-control', 'placeholder' => 'Title'])}}
            </div>
            <div class="form-group">
                {{Form::label('authors', 'Author(s)')}}
                {{Form::text('authors', '', ['class' => 'form-control', 'placeholder' => 'Please seperate each author with a comma (,)'])}}
            </div>
            <div class="form-group">
                {{Form::label('institutions', 'Institution(s)')}}
                {{Form::text('institutions', '', ['class' => 'form-control', 'placeholder' => 'Please seperate each institution with a comma (,)'])}}
            </div>
            <div class="form-group">
                {{Form::label('abstract', 'Abstract')}}
                <h6>(LaTeX encoding is supported, check <a  href="{{ route('faq') }}#latex" target="_blank" >FAQ</a> for more information)</h6>
                {{Form::textarea('abstract', '', ['id' => '', 'class' => 'form-control', 'placeholder' => 'Please copy and paste your abstract here'])}}
            </div>
            <!-- Keywords -->
            <div class="form-group">
                {{Form::label('keywords', 'Keyword(s)')}}
                {{Form::text('keywords', '', ['class' => 'form-control', 'placeholder' => 'Please seperate each keyword with a comma (,)', 'data-role' => 'tagsinput' ])}}
            </div>
            <!-- Attachments -->
            <div class="form-group">
                <h6>Please attach the paper here. Please only upload pdf files:</h6>
                {{Form::file('attached_files', array('multiple'=>false,'class'=>'send-btn', 'accept' => '.pdf'))}}
            </div>

            <br>
            <h3>Part 2: Implementation</h3>
            <h6>Software implementation is not mandatory but it is good way to demonstrate theory in real life. This is <i>not</i> the section for submitting code for speed benchmarking. Information and code submitted here will be publicly visible.</h6>
            <!-- Supported operations -->
            <div class="form-group">
                {{Form::label('programming_language', 'Select programming langue used to implement the encryption scheme')}}
                {!! Form::select('programming_language', array('C' => 'C', 'C++' => 'C++', 'Python' => 'Python', 'JAVA' => 'JAVA', 'JavaScript' => 'JavaScript', 'Other' => 'Other'), null, array('class' => 'form-control')) !!}
            </div>

            <div class="form-group" id="Other">
                {{Form::label('programming_language_other', 'Please write enter the programming langue you have used')}}
                {{Form::text('programming_language_other', '', ['class' => 'form-control', 'placeholder' => ''])}}
            </div>

            <div class="form-group">
                <h6>Select operations natively supported by the encryption scheme</h6>
                <span class="button-checkbox">
                    <button type="button" class="btn">Gate Operations</button>
                    <input type="checkbox" class="hidden" id="gate_operations" value="gate" name="supported_operations[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">Arithmetic Operations</button>
                    <input type="checkbox" class="hidden" id="arithmetic_operations" value="arithmetic" name="supported_operations[]" style="display:none;"/>
                </span>
            </div>

            <div class="form-group gate_operations">
                <h6>Select <i>gate</i> operations natively supported by the encryption scheme</h6>
                <span class="button-checkbox">
                    <button type="button" class="btn">AND</button>
                    <input type="checkbox" class="hidden" value="and" name="gate[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">NOT</button>
                    <input type="checkbox" class="hidden" value="not" name="gate[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">NAND</button>
                    <input type="checkbox" class="hidden" value="nand" name="gate[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">OR</button>
                    <input type="checkbox" class="hidden" value="or" name="gate[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">NOR</button>
                    <input type="checkbox" class="hidden" value="nor" name="gate[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">XOR</button>
                    <input type="checkbox" class="hidden" value="xor" name="gate[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">XNOR</button>
                    <input type="checkbox" class="hidden" value="xnor" name="gate[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">BUFFER</button>
                    <input type="checkbox" class="hidden" value="buffer" name="gate[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">MUX</button>
                    <input type="checkbox" class="hidden" value="mux" name="gate[]" style="display:none;"/>
                </span>
            </div>

            <div class="form-group arithmetic_operations">
                <h6>Select <i>arithmetic</i> operations natively supported by the encryption scheme</h6>
                <span class="button-checkbox">
                    <button type="button" class="btn">ADDITION</button>
                    <input type="checkbox" class="hidden" value="addition" name="arithmetic[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">SUBTRACTION</button>
                    <input type="checkbox" class="hidden" value="subtraction" name="arithmetic[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">MULTIPLICATION</button>
                    <input type="checkbox" class="hidden" value="multiplication" name="arithmetic[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">SQUARE</button>
                    <input type="checkbox" class="hidden" value="square" name="arithmetic[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">CUBE</button>
                    <input type="checkbox" class="hidden" value="cube" name="arithmetic[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">SQUARE ROOT</button>
                    <input type="checkbox" class="hidden" value="sroot" name="arithmetic[]" style="display:none;"/>
                </span>
            </div>
            <div class="form-group">
                {{Form::label('link', 'Website or GitHub link:')}}
                {{Form::text('link', '', ['class' => 'form-control', 'placeholder' => ''])}}
            </div>
            <!-- Attachments -->
            <div class="form-group">
                <h6>Please attach the implementation here. Please only upload .zip files:</h6>
                {{Form::file('attached_files_implementation', array('multiple' => false,'class' => 'send-btn', 'accept' => '.zip'))}}
            </div>

            <br>
            {{Form::submit('Submit', ['class'=>'btn btn-primary', "id" => "submit"])}}

        {!! Form::close() !!}
    </section>

    <!-- Toggle textbox based on the checkbox selection-->
    <script>

    $(function() {
        $(".gate_operations").hide();
        $(".arithmetic_operations").hide();

        $("#gate_operations").change(function() {
            if ( $(this).is(':checked') ) {
                $(".gate_operations").show();
            } else {
                $(".gate_operations").hide();
            }
        });

        $("#arithmetic_operations").change(function() {
            if ( $(this).is(':checked') ) {
                $(".arithmetic_operations").show();
            } else {
                $(".arithmetic_operations").hide();
            }
        });

    });
    </script>

    <!-- Checkbox Animation Script -->
    <script>
    $(function () {
    $('.button-checkbox').each(function () {

            // Settings
            var $widget = $(this),
                $button = $widget.find('button'),
                $checkbox = $widget.find('input:checkbox'),
                color = $button.data('color'),
                settings = {
                    on: {
                        icon: 'far fa-check-square'
                    },
                    off: {
                        icon: 'far fa-square'
                    }
                };

            // Event Handlers
            $button.on('click', function () {
                $checkbox.prop('checked', !$checkbox.is(':checked'));
                $checkbox.triggerHandler('change');
                updateDisplay();
            });
            $checkbox.on('change', function () {
                updateDisplay();
            });

            // Actions
            function updateDisplay() {
                var isChecked = $checkbox.is(':checked');

                // Set the button's state
                $button.data('state', (isChecked) ? "on" : "off");

                // Set the button's icon
                $button.find('.state-icon')
                    .removeClass()
                    .addClass('state-icon ' + settings[$button.data('state')].icon);

                // Update the button's color
                if (isChecked) {
                    $button
                        .removeClass('btn-outline-primary')
                        .addClass('btn-checkbox active');
                }
                else {
                    $button
                        .removeClass('btn-checkbox active')
                        .addClass('btn-outline-primary');
                }
            }

            // Initialization
            function init() {

                updateDisplay();

                // Inject the icon if applicable
                if ($button.find('.state-icon').length == 0) {
                    $button.prepend('<i class="state-icon ' + settings[$button.data('state')].icon + '"></i> ');
                }
            }
            init();
        });
    });
    </script>

    <!-- Toggle textbox based on the dropdown selection-->
    <script>

    $(function() {

        // run on change for the selectbox
        $( "#programming_language" ).change(function() {
            updateDurationDivs();
        });

        // handle the updating of the duration divs
        function updateDurationDivs() {
            // hide all form-duration-divs
            $('#Other').hide();

            var divKey = $( "#programming_language option:selected" ).val();
            $('#'+divKey).show();
        }

        // run at load, for the currently selected div to show up
        updateDurationDivs();

    });
    </script>

@endsection
