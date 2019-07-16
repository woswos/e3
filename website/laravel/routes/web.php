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

// Normal pages
Route::get('/', 'PagesController@index')->name('index');
Route::get('/submit', 'PagesController@submitNewScheme')->name('submitNewScheme');
Route::get('/about', 'PagesController@about')->name('about');
Route::get('/ranking', 'PagesController@ranking')->name('ranking');
Route::get('/faq', 'PagesController@faq')->name('faq');

// Schemes
Route::resource('scheme', 'SchemesController');

// Schemes
Route::get('/benchmark/create/{scheme_id}', 'BenchmarksController@create')->name('benchmark.create.id');
Route::resource('benchmark', 'BenchmarksController');

// Challenges
Route::get('/challenge/create/{scheme_id}', 'ChallengesController@create')->name('challenge.create.id');
Route::resource('challenge', 'ChallengesController');

// Solutions
//Route::get('/solution/attempt/{destination?}/{parameter?}', 'SolutionsController@attempt')->name('solution.attempt');
Route::get('/solution/create/{scheme_id}', 'SolutionsController@create')->name('solution.create.id');
Route::resource('solution', 'SolutionsController');

// Authentication stuff
Auth::routes();
Auth::routes(['verify' => true]);
Route::get('/changepassword','DashboardController@showChangePasswordForm');
Route::post('/changepassword','DashboardController@changePassword')->name('changepassword');

// Dashboard
Route::get('/dashboard', 'DashboardController@index')->name('dashboard');
