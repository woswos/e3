<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateImplementationsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('implementations', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->string('scheme_id'); // foreign key for relating to schemes
            $table->string('programming_language')->nullable();
            $table->string('programming_language_other')->nullable();

            $table->string('supported_operations')->nullable();
            $table->string('gate')->nullable();
            $table->string('arithmetic')->nullable();

            $table->string('link')->nullable();

            $table->string('attached_files_implementation')->nullable();
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('implementations');
    }
}
