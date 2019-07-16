@extends('layouts/app')

@section('content')
    <section class="">
        <div class="container">
        <h1>Submit code for benchmarking</h1>
        <h6><i>Please review the <a href="{{ route('faq') }}#benchmark" target="_blank">submission instructions</a> before submitting any code for benchmarking</i></h6>

        {!! Form::open(['action' => 'BenchmarksController@store', 'method' => 'POST', 'enctype' => 'multipart/form-data']) !!}
            <!-- Supported operations -->
            <div class="form-group">
                {{Form::label('programming_language', 'Select programming langue used to implement the encryption scheme')}}
                {!! Form::select('programming_language', array('C++' => 'C++', 'C' => 'C', 'Python' => 'Python', 'JAVA' => 'JAVA', 'JavaScript' => 'JavaScript', 'Other' => 'Other'), null, array('class' => 'form-control')) !!}
            </div>

            <div class="form-group" id="Other">
                {{Form::label('programming_language_other', 'Please write enter the programming langue you have used')}}
                {{Form::text('programming_language_other', '', ['class' => 'form-control', 'placeholder' => ''])}}
            </div>

            <div class="form-group">
                <h6>Select whether you implemented gate or arithmetic operations in the code that you are submitting</h6>
                <span class="button-checkbox">
                    <button type="button" class="btn" id="gate_operations_button">Gate Operations</button>
                    <input type="checkbox" class="hidden" id="gate_operations" value="gate" name="supported_operations[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn" id="arithmetic_operations_button">Arithmetic Operations</button>
                    <input type="checkbox" class="hidden" id="arithmetic_operations" value="arithmetic" name="supported_operations[]" style="display:none;"/>
                </span>
            </div>

            <div class="form-group gate_operations">
                <h6>Select <i>gate</i> operations implemented in the code that you are submitting</h6>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">NAND</button>
                    <input type="checkbox" class="hidden" value="nand" name="gate[]" style="display:none;"/>
                </span>
                <span class="button-checkbox" style="padding-left: 5px;">
                    <button type="button" class="btn">NOR</button>
                    <input type="checkbox" class="hidden" value="nor" name="gate[]" style="display:none;"/>
                </span>
            </div>

            <div class="form-group arithmetic_operations">
                <h6>Select <i>arithmetic</i> operations implemented in the code that you are submitting</h6>
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
            <!-- Attachments -->
            <div class="form-group">
                <h6>Please attach the implementation here. Please only upload .zip files:</h6>
                {{Form::file('attached_files_benchmark', array('multiple' => false,'class' => 'send-btn', 'accept' => '.zip'))}}
            </div>

            {{ Form::hidden('scheme_id', $scheme->id ) }}

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
                $("#arithmetic_operations_button").attr('disabled', 'disabled');
                $(".gate_operations").show();
            } else {
                $("#arithmetic_operations_button").attr('disabled', false);
                $(".gate_operations").hide();
            }
        });

        $("#arithmetic_operations").change(function() {
            if ( $(this).is(':checked') ) {
                $("#gate_operations_button").attr('disabled', 'disabled');
                $(".arithmetic_operations").show();
            } else {
                $("#gate_operations_button").attr('disabled', false);
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
