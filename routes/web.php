<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', 'PagesController@index')->name('index');
Route::get('/submit', 'PagesController@submitNewScheme')->name('submitNewScheme');
Route::get('/about', 'PagesController@about')->name('about');

Route::resource('scheme', 'SchemesController');

/*
Route::get('/user/{id}', function ($id) {
    return "This is user ".$id;
});


Route::get('/user/{id}/{name}', function ($id, $name) {
    return "This is user ".$id." and name is ".$name;
});
*/
