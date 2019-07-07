<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateChallengesTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('challenges', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->string('scheme_id'); // foreign key for relating to schemes
            $table->string('title')->nullable();
            $table->string('prize')->nullable();
            $table->mediumText('explanation')->nullable();
            $table->mediumText('difficulty')->nullable();
            $table->mediumText('attempts')->nullable();
            $table->string('flag')->nullable();
            $table->boolean('solved')->nullable();
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
        Schema::dropIfExists('challenges');
    }
}
