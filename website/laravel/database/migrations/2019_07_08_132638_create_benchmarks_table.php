<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateBenchmarksTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('benchmarks', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->string('scheme_id'); // foreign key for relating to schemes

            $table->mediumText('speed')->nullable();

            $table->string('programming_language')->nullable();
            $table->string('programming_language_other')->nullable();

            $table->string('supported_operations')->nullable();
            $table->string('gate')->nullable();
            $table->string('arithmetic')->nullable();

            $table->string('attached_files')->nullable();
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
        Schema::dropIfExists('benchmarks');
    }
}
