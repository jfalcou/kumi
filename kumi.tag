<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.9.8">
  <compound kind="struct">
    <name>kumi::all_unique_names</name>
    <filename>structkumi_1_1all__unique__names.html</filename>
    <templarg>typename Ints</templarg>
    <templarg>typename... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::all_uniques</name>
    <filename>structkumi_1_1all__uniques.html</filename>
    <templarg>typename Ints</templarg>
    <templarg>typename... Ts</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::as</name>
    <filename>structkumi_1_1as.html</filename>
    <templarg>typename T</templarg>
    <member kind="typedef">
      <type>T</type>
      <name>type</name>
      <anchorfile>structkumi_1_1as.html</anchorfile>
      <anchor>ae0ed33d79b1955359c95eb5e572f7305</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::as_tuple</name>
    <filename>structkumi_1_1as__tuple.html</filename>
    <templarg>typename T</templarg>
    <templarg>template&lt; typename... &gt; class Meta</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::_::builder</name>
    <filename>structkumi_1_1___1_1builder.html</filename>
    <templarg>kumi::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::element</name>
    <filename>structkumi_1_1element.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::field_capture</name>
    <filename>structkumi_1_1field__capture.html</filename>
    <templarg>str ID</templarg>
    <templarg>typename T</templarg>
    <member kind="typedef">
      <type>T</type>
      <name>type</name>
      <anchorfile>structkumi_1_1field__capture.html</anchorfile>
      <anchor>add68513ed59cc66d84b5e197470331fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>name</name>
      <anchorfile>structkumi_1_1field__capture.html</anchorfile>
      <anchor>ae51b43553f7b63a2cf9d032e02324086</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>capture_field</name>
      <anchorfile>group__product__types_gafc8e80ba53336a0142f3267959c1ba71.html</anchorfile>
      <anchor>gafc8e80ba53336a0142f3267959c1ba71</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>field_value_of</name>
      <anchorfile>group__product__types_gad7a01eb2dfa2f318b75141023ed56d58.html</anchorfile>
      <anchor>gad7a01eb2dfa2f318b75141023ed56d58</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>name_of</name>
      <anchorfile>group__product__types_ga05150d8b3720e050874ad6144a164fde.html</anchorfile>
      <anchor>ga05150d8b3720e050874ad6144a164fde</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>group__product__types.html</anchorfile>
      <anchor>gad9e237c94f8427a7ddfafb8fb0cc4428</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field_capture const &amp;w) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::field_name</name>
    <filename>structkumi_1_1field__name.html</filename>
    <templarg>str ID</templarg>
    <member kind="function">
      <type>constexpr</type>
      <name>operator str</name>
      <anchorfile>structkumi_1_1field__name.html</anchorfile>
      <anchor>a80148a15bcc8e1a15459031d09cc4ebf</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr field_capture&lt; ID, std::unwrap_ref_decay_t&lt; T &gt; &gt;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1field__name_a0821838da7dda6e5d69225c191048a4e.html</anchorfile>
      <anchor>a0821838da7dda6e5d69225c191048a4e</anchor>
      <arglist>(T v) const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>name</name>
      <anchorfile>structkumi_1_1field__name.html</anchorfile>
      <anchor>a5611993be7e766b8058e96ddd8ded5b7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::_::get_field_by_name&lt; Ref, std::index_sequence&lt; I... &gt;, Fields... &gt;</name>
    <filename>structkumi_1_1___1_1get__field__by__name_3_01Ref_00_01std_1_1index__sequence_3_01I_8_8_8_01_4_00_01Fields_8_8_8_01_4.html</filename>
    <templarg>typename Ref</templarg>
    <templarg>std::size_t... I</templarg>
    <templarg>typename... Fields</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::_::get_field_by_type</name>
    <filename>structkumi_1_1___1_1get__field__by__type.html</filename>
    <templarg>typename Ref</templarg>
    <templarg>typename... Fields</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::index_t</name>
    <filename>structkumi_1_1index__t.html</filename>
    <templarg>std::size_t N</templarg>
    <member kind="function">
      <type>constexpr</type>
      <name>operator std::size_t</name>
      <anchorfile>structkumi_1_1index__t.html</anchorfile>
      <anchor>a4dd6abb0a1663aa1f355ee416ee3083e</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>value</name>
      <anchorfile>structkumi_1_1index__t.html</anchorfile>
      <anchor>ab659f5d62c79ae49fe525448df86765b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::indexes_t</name>
    <filename>structkumi_1_1indexes__t.html</filename>
    <templarg>indexer... V</templarg>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1indexes__t.html</anchorfile>
      <anchor>a6562f464b767bcc8b38b05ba378928b5</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1indexes__t.html</anchorfile>
      <anchor>ae57341a487116b86f5d2f9a3a31607a4</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1indexes__t.html</anchorfile>
      <anchor>a6562f464b767bcc8b38b05ba378928b5</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1indexes__t.html</anchorfile>
      <anchor>ae57341a487116b86f5d2f9a3a31607a4</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get_index</name>
      <anchorfile>structkumi_1_1indexes__t.html</anchorfile>
      <anchor>ab13af7957b1760751a2615e076454db7</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>structkumi_1_1indexes__t_a3fb9428a3c6e9260c0a36fd92a7f8621.html</anchorfile>
      <anchor>a3fb9428a3c6e9260c0a36fd92a7f8621</anchor>
      <arglist>(indexes_t &amp;i) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>structkumi_1_1indexes__t.html</anchorfile>
      <anchor>a4dcaa01fe6d481ace4d5a83576acdcc8</anchor>
      <arglist>(indexes_t const &amp;i) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::is_homogeneous</name>
    <filename>structkumi_1_1is__homogeneous.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_product_type</name>
    <filename>structkumi_1_1is__product__type.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename Enable</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_record_type</name>
    <filename>structkumi_1_1is__record__type.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename Enable</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::member</name>
    <filename>structkumi_1_1member.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::raw_element</name>
    <filename>structkumi_1_1raw__element.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::raw_member</name>
    <filename>structkumi_1_1raw__member.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::record</name>
    <filename>structkumi_1_1record.html</filename>
    <templarg>typename... Ts</templarg>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__algorithm_ga9ae63f9221db181d1c0f0c8ff3a99b06.html</anchorfile>
      <anchor>ga9ae63f9221db181d1c0f0c8ff3a99b06</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_ga9ae63f9221db181d1c0f0c8ff3a99b06.html</anchorfile>
      <anchor>ga9ae63f9221db181d1c0f0c8ff3a99b06</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>forward_as_record</name>
      <anchorfile>group__record_ga508677aacba8fa46c42516e15c92ab3c.html</anchorfile>
      <anchor>ga508677aacba8fa46c42516e15c92ab3c</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; field_capture&lt; Fields, Ts &amp;&amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_record</name>
      <anchorfile>group__record_gae8fa9564a0714fe540bda228f2bb4001.html</anchorfile>
      <anchor>gae8fa9564a0714fe540bda228f2bb4001</anchor>
      <arglist>(Ts &amp;&amp;...ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__record_ga20a4570d5712ffff83908aab1753b614.html</anchorfile>
      <anchor>ga20a4570d5712ffff83908aab1753b614</anchor>
      <arglist>(Type &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__record_gabc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>gabc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__record_gabc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>gabc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>forward_as_record</name>
      <anchorfile>group__record_ga508677aacba8fa46c42516e15c92ab3c.html</anchorfile>
      <anchor>ga508677aacba8fa46c42516e15c92ab3c</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; field_capture&lt; Fields, Ts &amp;&amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_record</name>
      <anchorfile>group__record_gae8fa9564a0714fe540bda228f2bb4001.html</anchorfile>
      <anchor>gae8fa9564a0714fe540bda228f2bb4001</anchor>
      <arglist>(Ts &amp;&amp;...ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__record_ga20a4570d5712ffff83908aab1753b614.html</anchorfile>
      <anchor>ga20a4570d5712ffff83908aab1753b614</anchor>
      <arglist>(Type &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__record_gabc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>gabc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__record_gabc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>gabc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::size</name>
    <filename>structkumi_1_1size.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::str</name>
    <filename>structkumi_1_1str.html</filename>
  </compound>
  <compound kind="class">
    <name>kumi::tuple</name>
    <filename>structkumi_1_1tuple.html</filename>
    <templarg>typename... Ts</templarg>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator()</name>
      <anchorfile>structkumi_1_1tuple_ab87916d0fe851c409de6cc448521b4da.html</anchorfile>
      <anchor>ab87916d0fe851c409de6cc448521b4da</anchor>
      <arglist>(Function &amp;&amp;f) const &amp;noexcept(noexcept(kumi::apply(KUMI_FWD(f), *this))) -&gt; decltype(kumi::apply(KUMI_FWD(f), *this))</arglist>
    </member>
    <member kind="function">
      <type>constexpr tuple &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad876de41968b5ee06bccf70695592f54</anchor>
      <arglist>(tuple&lt; Us... &gt; &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>constexpr tuple &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1tuple_a4fd625da2ba811927789a6c838330144.html</anchorfile>
      <anchor>a4fd625da2ba811927789a6c838330144</anchor>
      <arglist>(tuple&lt; Us... &gt; const &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a04c4c32268e3d932f2ededca2ec90d69.html</anchorfile>
      <anchor>a04c4c32268e3d932f2ededca2ec90d69</anchor>
      <arglist>(index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a6a47abda2bc4a351f205ef879f51b956</anchor>
      <arglist>(index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a9f71bb60c1a0d3e9e8202cc502d8cf91</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa74d8923542669cdfbeaadc3c51e0e3f</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a8884e1a67d2f48a3ef8cfe619dbb6c28.html</anchorfile>
      <anchor>a8884e1a67d2f48a3ef8cfe619dbb6c28</anchor>
      <arglist>(as&lt; T &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>abb027a7814d28e064a141ac6badf8ac0</anchor>
      <arglist>(as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a57629c3191e8ac343759f181b37e3069</anchor>
      <arglist>(as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a3fc764a0814b32d175bc54813673c1bd</anchor>
      <arglist>(as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a14421b52c648486b4ceb2008f00f5b29.html</anchorfile>
      <anchor>a14421b52c648486b4ceb2008f00f5b29</anchor>
      <arglist>(field_name&lt; Name &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a1968c93cbd710cb76a866da68853bbcb</anchor>
      <arglist>(field_name&lt; Name &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ae19037279381fea365feac52f6ebad51</anchor>
      <arglist>(field_name&lt; Name &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a6ff61c11972342b38282a3b49b62885c</anchor>
      <arglist>(field_name&lt; Name &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cast</name>
      <anchorfile>structkumi_1_1tuple_a9eb39bbd2e8e1d97a31047113eb5f55e.html</anchorfile>
      <anchor>a9eb39bbd2e8e1d97a31047113eb5f55e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a0d0957e5314d780693c3d67344a42b3e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>af1a74e00134be29916bb7fb6e8cda5f6</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>names</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a5146296246d19f751e089b380fe31bb1</anchor>
      <arglist>() noexcept -&gt; tuple&lt; decltype(name_of(as&lt; Ts &gt;{}))... &gt;</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gaf6739a069131e315597688e5b3cf5df9</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, tuple const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>forward_as_tuple</name>
      <anchorfile>group__tuple_ga5c5ba567f7ec305505f44bf70c67b6db.html</anchorfile>
      <anchor>ga5c5ba567f7ec305505f44bf70c67b6db</anchor>
      <arglist>(Ts &amp;&amp;...ts) -&gt; tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__tuple_ga6cde1bebcc6150b864820645ad4cf14f.html</anchorfile>
      <anchor>ga6cde1bebcc6150b864820645ad4cf14f</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a04c4c32268e3d932f2ededca2ec90d69.html</anchorfile>
      <anchor>a04c4c32268e3d932f2ededca2ec90d69</anchor>
      <arglist>(index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a6a47abda2bc4a351f205ef879f51b956</anchor>
      <arglist>(index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a9f71bb60c1a0d3e9e8202cc502d8cf91</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa74d8923542669cdfbeaadc3c51e0e3f</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a8884e1a67d2f48a3ef8cfe619dbb6c28.html</anchorfile>
      <anchor>a8884e1a67d2f48a3ef8cfe619dbb6c28</anchor>
      <arglist>(as&lt; T &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>abb027a7814d28e064a141ac6badf8ac0</anchor>
      <arglist>(as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a57629c3191e8ac343759f181b37e3069</anchor>
      <arglist>(as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a3fc764a0814b32d175bc54813673c1bd</anchor>
      <arglist>(as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a14421b52c648486b4ceb2008f00f5b29.html</anchorfile>
      <anchor>a14421b52c648486b4ceb2008f00f5b29</anchor>
      <arglist>(field_name&lt; Name &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a1968c93cbd710cb76a866da68853bbcb</anchor>
      <arglist>(field_name&lt; Name &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ae19037279381fea365feac52f6ebad51</anchor>
      <arglist>(field_name&lt; Name &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a6ff61c11972342b38282a3b49b62885c</anchor>
      <arglist>(field_name&lt; Name &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cast</name>
      <anchorfile>structkumi_1_1tuple_a9eb39bbd2e8e1d97a31047113eb5f55e.html</anchorfile>
      <anchor>a9eb39bbd2e8e1d97a31047113eb5f55e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a0d0957e5314d780693c3d67344a42b3e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>af1a74e00134be29916bb7fb6e8cda5f6</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>names</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a5146296246d19f751e089b380fe31bb1</anchor>
      <arglist>() noexcept -&gt; tuple&lt; decltype(name_of(as&lt; Ts &gt;{}))... &gt;</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator==</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gaf074114f7e38446c5e298e6701e8a54b</anchor>
      <arglist>(tuple const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&lt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gac0b978b3e13c057400e145cc8ac174b0</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&lt;=</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>ga03b20df5887479d4b7277e30302266ea</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&gt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>ga741431fe551f58d39edd28b6f6d005ae</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&gt;=</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>ga6b3f89a6d6b94821ab32117291342a64</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>forward_as_tuple</name>
      <anchorfile>group__tuple_ga5c5ba567f7ec305505f44bf70c67b6db.html</anchorfile>
      <anchor>ga5c5ba567f7ec305505f44bf70c67b6db</anchor>
      <arglist>(Ts &amp;&amp;...ts) -&gt; tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__tuple_ga6cde1bebcc6150b864820645ad4cf14f.html</anchorfile>
      <anchor>ga6cde1bebcc6150b864820645ad4cf14f</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::_::unique</name>
    <filename>structkumi_1_1___1_1unique.html</filename>
    <templarg>std::size_t</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::_::unique_name</name>
    <filename>structkumi_1_1___1_1unique__name.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::_::unique_name&lt; I, kumi::field_capture&lt; Name, T &gt; &gt;</name>
    <filename>structkumi_1_1___1_1unique__name_3_01I_00_01kumi_1_1field__capture_3_01Name_00_01T_01_4_01_4.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>kumi::str Name</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::unit</name>
    <filename>structkumi_1_1unit.html</filename>
  </compound>
  <compound kind="struct">
    <name>kumi::_::value_as</name>
    <filename>structkumi_1_1___1_1value__as.html</filename>
    <templarg>auto NTTP</templarg>
  </compound>
  <compound kind="concept">
    <name>kumi::compatible_product_types</name>
    <filename>conceptkumi_1_1compatible__product__types.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::contains_field</name>
    <filename>conceptkumi_1_1contains__field.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::contains_type</name>
    <filename>conceptkumi_1_1contains__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::empty_product_type</name>
    <filename>conceptkumi_1_1empty__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::entirely_uniquely_named</name>
    <filename>conceptkumi_1_1entirely__uniquely__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::equality_comparable</name>
    <filename>conceptkumi_1_1equality__comparable.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::equivalent</name>
    <filename>conceptkumi_1_1equivalent.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::follows_same_semantic</name>
    <filename>conceptkumi_1_1follows__same__semantic.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::has_named_fields</name>
    <filename>conceptkumi_1_1has__named__fields.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::homogeneous_product_type</name>
    <filename>conceptkumi_1_1homogeneous__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::index_map</name>
    <filename>conceptkumi_1_1index__map.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::indexer</name>
    <filename>conceptkumi_1_1indexer.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::is_fully_named</name>
    <filename>conceptkumi_1_1is__fully__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::named_equality_comparable</name>
    <filename>conceptkumi_1_1named__equality__comparable.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::non_empty_product_type</name>
    <filename>conceptkumi_1_1non__empty__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::product_type</name>
    <filename>conceptkumi_1_1product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::record_type</name>
    <filename>conceptkumi_1_1record__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::sized_product_type</name>
    <filename>conceptkumi_1_1sized__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::sized_product_type_or_more</name>
    <filename>conceptkumi_1_1sized__product__type__or__more.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::std_tuple_compatible</name>
    <filename>conceptkumi_1_1std__tuple__compatible.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::uniquely_named</name>
    <filename>conceptkumi_1_1uniquely__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::uniquely_typed</name>
    <filename>conceptkumi_1_1uniquely__typed.html</filename>
  </compound>
  <compound kind="namespace">
    <name>kumi</name>
    <filename>namespacekumi.html</filename>
    <class kind="struct">kumi::all_unique_names</class>
    <class kind="struct">kumi::all_uniques</class>
    <class kind="class">kumi::as</class>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="struct">kumi::element</class>
    <class kind="class">kumi::field_capture</class>
    <class kind="class">kumi::field_name</class>
    <class kind="struct">kumi::index_t</class>
    <class kind="class">kumi::indexes_t</class>
    <class kind="struct">kumi::is_homogeneous</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::is_record_type</class>
    <class kind="struct">kumi::member</class>
    <class kind="struct">kumi::raw_element</class>
    <class kind="struct">kumi::raw_member</class>
    <class kind="class">kumi::record</class>
    <class kind="struct">kumi::size</class>
    <class kind="class">kumi::str</class>
    <class kind="class">kumi::tuple</class>
    <class kind="class">kumi::unit</class>
    <concept>kumi::std_tuple_compatible</concept>
    <concept>kumi::product_type</concept>
    <concept>kumi::record_type</concept>
    <concept>kumi::sized_product_type</concept>
    <concept>kumi::sized_product_type_or_more</concept>
    <concept>kumi::empty_product_type</concept>
    <concept>kumi::non_empty_product_type</concept>
    <concept>kumi::index_map</concept>
    <concept>kumi::indexer</concept>
    <concept>kumi::homogeneous_product_type</concept>
    <concept>kumi::equality_comparable</concept>
    <concept>kumi::has_named_fields</concept>
    <concept>kumi::is_fully_named</concept>
    <concept>kumi::uniquely_typed</concept>
    <concept>kumi::uniquely_named</concept>
    <concept>kumi::entirely_uniquely_named</concept>
    <concept>kumi::contains_type</concept>
    <concept>kumi::contains_field</concept>
    <concept>kumi::equivalent</concept>
    <concept>kumi::named_equality_comparable</concept>
    <concept>kumi::follows_same_semantic</concept>
    <concept>kumi::compatible_product_types</concept>
    <member kind="function">
      <type>constexpr auto</type>
      <name>all_of</name>
      <anchorfile>group__queries_gabbce9eea5df0239358c6a09bf24fb667.html</anchorfile>
      <anchor>gabbce9eea5df0239358c6a09bf24fb667</anchor>
      <arglist>(T &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>all_of</name>
      <anchorfile>group__queries_ga91aebbbef8db8781c2c48bc814beed9b.html</anchorfile>
      <anchor>ga91aebbbef8db8781c2c48bc814beed9b</anchor>
      <arglist>(T &amp;&amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>all_unique</name>
      <anchorfile>group__generators_gacf670e19ac40c8981f52ad0783a3e483.html</anchorfile>
      <anchor>gacf670e19ac40c8981f52ad0783a3e483</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>any_of</name>
      <anchorfile>group__queries_ga1c7e88598454517558e84d377ff681ce.html</anchorfile>
      <anchor>ga1c7e88598454517558e84d377ff681ce</anchor>
      <arglist>(T &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>any_of</name>
      <anchorfile>group__queries_ga4564d211f8b879d1ff2b3fb1a7fa525f.html</anchorfile>
      <anchor>ga4564d211f8b879d1ff2b3fb1a7fa525f</anchor>
      <arglist>(T &amp;&amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>apply</name>
      <anchorfile>group__transforms_ga2c808f8956ae85b42b9b8a8ed09cc371.html</anchorfile>
      <anchor>ga2c808f8956ae85b42b9b8a8ed09cc371</anchor>
      <arglist>(Function &amp;&amp;f, Tuple &amp;&amp;t) noexcept(_::supports_nothrow_apply&lt; Function &amp;&amp;, Tuple &amp;&amp; &gt;)</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>as_flat_ptr</name>
      <anchorfile>group__generators_ga418f0a47f05b67dbb354d274dee63e4e.html</anchorfile>
      <anchor>ga418f0a47f05b67dbb354d274dee63e4e</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>back</name>
      <anchorfile>group__utility_ga6d1e220549b74a2234e7ce58bf791d3e.html</anchorfile>
      <anchor>ga6d1e220549b74a2234e7ce58bf791d3e</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_and</name>
      <anchorfile>group__reductions_ga086ae741edfc80131295802c31e08af9.html</anchorfile>
      <anchor>ga086ae741edfc80131295802c31e08af9</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_and</name>
      <anchorfile>group__reductions_ga491ecadaaedfe84e927302683f108625.html</anchorfile>
      <anchor>ga491ecadaaedfe84e927302683f108625</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_or</name>
      <anchorfile>group__reductions_gad66c3ad56b3536942c960c2cad1fabcf.html</anchorfile>
      <anchor>gad66c3ad56b3536942c960c2cad1fabcf</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_or</name>
      <anchorfile>group__reductions_ga74ca2a5811c0ba2e5b0c07f6aea15d90.html</anchorfile>
      <anchor>ga74ca2a5811c0ba2e5b0c07f6aea15d90</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cartesian_product</name>
      <anchorfile>group__generators_ga4d1776863d20d012aedf130ead1db453.html</anchorfile>
      <anchor>ga4d1776863d20d012aedf130ead1db453</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cat</name>
      <anchorfile>group__generators_gab6e93bf9bc4d4efb456d07eb820d594e.html</anchorfile>
      <anchor>gab6e93bf9bc4d4efb456d07eb820d594e</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>chunks</name>
      <anchorfile>group__generators_ga391aae5adab10d9be8e9cbf5be4f0f64.html</anchorfile>
      <anchor>ga391aae5adab10d9be8e9cbf5be4f0f64</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>common_product_type</name>
      <anchorfile>group__traits_ga3226fe6731192617509a4baae1f74655.html</anchorfile>
      <anchor>ga3226fe6731192617509a4baae1f74655</anchor>
      <arglist>(Ts...)</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>count</name>
      <anchorfile>group__queries_ga8f859d30f200d3a636817fb5160e342d.html</anchorfile>
      <anchor>ga8f859d30f200d3a636817fb5160e342d</anchor>
      <arglist>(T &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>count_if</name>
      <anchorfile>group__queries_gafb9e4c9675c1fccd1ba31f1b17ac1387.html</anchorfile>
      <anchor>gafb9e4c9675c1fccd1ba31f1b17ac1387</anchor>
      <arglist>(T &amp;&amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>extract</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>acca7201e7087872ec75b51eecfa5c1d6</anchor>
      <arglist>(Tuple &amp;&amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>extract</name>
      <anchorfile>group__generators_ga5bafcaeb0a60662cddff54c4ca663c50.html</anchorfile>
      <anchor>ga5bafcaeb0a60662cddff54c4ca663c50</anchor>
      <arglist>(Tuple &amp;&amp;t, index_t&lt; I0 &gt; i0, index_t&lt; I1 &gt; i1) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fill</name>
      <anchorfile>group__generators_gac1f2b67c16429675ca7b9106793f9001.html</anchorfile>
      <anchor>gac1f2b67c16429675ca7b9106793f9001</anchor>
      <arglist>(T const &amp;v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>filter</name>
      <anchorfile>group__generators_ga092340ad03e4970fb79d4bc4872e4a2d.html</anchorfile>
      <anchor>ga092340ad03e4970fb79d4bc4872e4a2d</anchor>
      <arglist>(T &amp;&amp;tup) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>filter_not</name>
      <anchorfile>group__generators_gad866fde689ca139c15ddab16cd8be536.html</anchorfile>
      <anchor>gad866fde689ca139c15ddab16cd8be536</anchor>
      <arglist>(T &amp;&amp;tup) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>flatten</name>
      <anchorfile>group__generators_ga6a021e42590689a905a2d8268c860838.html</anchorfile>
      <anchor>ga6a021e42590689a905a2d8268c860838</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>flatten_all</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a7fcee37f7e0ccc2adad9f91fa48fd34b</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>flatten_all</name>
      <anchorfile>group__generators_ga5c0915917db751d43c4a07eb884945cc.html</anchorfile>
      <anchor>ga5c0915917db751d43c4a07eb884945cc</anchor>
      <arglist>(T &amp;&amp;t, Func &amp;&amp;f)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_left</name>
      <anchorfile>group__reductions_gaed0714239b395a2ac14d3a6a3ec3f44c.html</anchorfile>
      <anchor>gaed0714239b395a2ac14d3a6a3ec3f44c</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_left</name>
      <anchorfile>group__reductions_gaf5c5a77520eb5db15716f55fdb413579.html</anchorfile>
      <anchor>gaf5c5a77520eb5db15716f55fdb413579</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_right</name>
      <anchorfile>group__reductions_ga20c7d2a3b7e7044f95ec352e64cd1b27.html</anchorfile>
      <anchor>ga20c7d2a3b7e7044f95ec352e64cd1b27</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_right</name>
      <anchorfile>group__reductions_gaa2bdd088d82f635a5c52c6dd5bdeaaf2.html</anchorfile>
      <anchor>gaa2bdd088d82f635a5c52c6dd5bdeaaf2</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each</name>
      <anchorfile>group__transforms_ga1276dff11987989fc804ebe3d3804678.html</anchorfile>
      <anchor>ga1276dff11987989fc804ebe3d3804678</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_field</name>
      <anchorfile>group__transforms_ga8e05313a97d85b3fa24c9650d661db74.html</anchorfile>
      <anchor>ga8e05313a97d85b3fa24c9650d661db74</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_index</name>
      <anchorfile>group__transforms_ga39e65f96d9880dd5b1e08b8dc01993a1.html</anchorfile>
      <anchor>ga39e65f96d9880dd5b1e08b8dc01993a1</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_tuple</name>
      <anchorfile>group__utility_gad8e73ef5a6e05c2ae2db0bcfa860de48.html</anchorfile>
      <anchor>gad8e73ef5a6e05c2ae2db0bcfa860de48</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>front</name>
      <anchorfile>group__utility_gae40b8dfe98266c4f62395c369833eef3.html</anchorfile>
      <anchor>gae40b8dfe98266c4f62395c369833eef3</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>generate</name>
      <anchorfile>group__generators_gaf6a234ed8630b3928724cf8fefbc9c6d.html</anchorfile>
      <anchor>gaf6a234ed8630b3928724cf8fefbc9c6d</anchor>
      <arglist>(Function const &amp;f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>indexes</name>
      <anchorfile>group__utility_gad9d978893c5e64520e0b0d83d133c26c.html</anchorfile>
      <anchor>gad9d978893c5e64520e0b0d83d133c26c</anchor>
      <arglist>(Ts... ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>indexes_t</name>
      <anchorfile>group__utility_gaccc36e7b78d9da78548eebf22ea28492.html</anchorfile>
      <anchor>gaccc36e7b78d9da78548eebf22ea28492</anchor>
      <arglist>(Ts...) -&gt; indexes_t&lt; Ts... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a0ee72852cfb635dcde54be778d008a1f</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>group__reductions_gaf73310d42c59ac2d79ea21586ea46265.html</anchorfile>
      <anchor>gaf73310d42c59ac2d79ea21586ea46265</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>iota</name>
      <anchorfile>group__generators_ga19ced0b66d1e3dae7bfa60f7def6914f.html</anchorfile>
      <anchor>ga19ced0b66d1e3dae7bfa60f7def6914f</anchor>
      <arglist>(T v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>locate</name>
      <anchorfile>group__queries_gaa67dd04ff61ae1741dd46f6a48d6ef21.html</anchorfile>
      <anchor>gaa67dd04ff61ae1741dd46f6a48d6ef21</anchor>
      <arglist>(Tuple &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map</name>
      <anchorfile>group__transforms_ga18c38e2efc4f46e7a4758b0aff9a46ea.html</anchorfile>
      <anchor>ga18c38e2efc4f46e7a4758b0aff9a46ea</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_field</name>
      <anchorfile>group__transforms_ga45789f4ba9e8d862296c5e6fc5178026.html</anchorfile>
      <anchor>ga45789f4ba9e8d862296c5e6fc5178026</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_index</name>
      <anchorfile>group__transforms_ga62f3925c2071557401ba32bde816e49c.html</anchorfile>
      <anchor>ga62f3925c2071557401ba32bde816e49c</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>max</name>
      <anchorfile>group__reductions_ga72159dc27be6b9aed9cc1d12ca019f28.html</anchorfile>
      <anchor>ga72159dc27be6b9aed9cc1d12ca019f28</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>max</name>
      <anchorfile>group__reductions_gae173eedc8b731830ea5df23aec9f14fa.html</anchorfile>
      <anchor>gae173eedc8b731830ea5df23aec9f14fa</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>max_flat</name>
      <anchorfile>group__reductions_gafa660a662111704882e6c9005f34f818.html</anchorfile>
      <anchor>gafa660a662111704882e6c9005f34f818</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>members_of</name>
      <anchorfile>group__algorithm_gaba7cff8d6c8c8b6d03ca78df63c9eba0.html</anchorfile>
      <anchor>gaba7cff8d6c8c8b6d03ca78df63c9eba0</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>min</name>
      <anchorfile>group__reductions_ga2e588148a9b7eda028da7963770a5010.html</anchorfile>
      <anchor>ga2e588148a9b7eda028da7963770a5010</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>min</name>
      <anchorfile>group__reductions_gab860bed731b3d7499e9d85b1a3ce57b6.html</anchorfile>
      <anchor>gab860bed731b3d7499e9d85b1a3ce57b6</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>min_flat</name>
      <anchorfile>group__reductions_ga931f495837b8f1c878fbb8a625ca9442.html</anchorfile>
      <anchor>ga931f495837b8f1c878fbb8a625ca9442</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>none_of</name>
      <anchorfile>group__queries_ga642ca90fe3a084caace28ee7d110ed2a.html</anchorfile>
      <anchor>ga642ca90fe3a084caace28ee7d110ed2a</anchor>
      <arglist>(Tuple &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>none_of</name>
      <anchorfile>group__queries_gac3f39b08030156afeba4800b3a527565.html</anchorfile>
      <anchor>gac3f39b08030156afeba4800b3a527565</anchor>
      <arglist>(Tuple &amp;&amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&quot;&quot;_c</name>
      <anchorfile>group__utility_ga60825dffaa5ee2c50e1d1a24057bdcf1.html</anchorfile>
      <anchor>ga60825dffaa5ee2c50e1d1a24057bdcf1</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&quot;&quot;_f</name>
      <anchorfile>group__utility_gac6640fd24bd6244cbed251ed2e689d83.html</anchorfile>
      <anchor>gac6640fd24bd6244cbed251ed2e689d83</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>partition</name>
      <anchorfile>group__generators_ga247e68735773ce448a9fc25f02d7dca0.html</anchorfile>
      <anchor>ga247e68735773ce448a9fc25f02d7dca0</anchor>
      <arglist>(T &amp;&amp;tup) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>pop_back</name>
      <anchorfile>group__generators_gaeb73a506f59ec92ddafbf7aa93fb5547.html</anchorfile>
      <anchor>gaeb73a506f59ec92ddafbf7aa93fb5547</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>pop_front</name>
      <anchorfile>group__generators_ga742995cb887d0116de190db250c3257d.html</anchorfile>
      <anchor>ga742995cb887d0116de190db250c3257d</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>predicate</name>
      <anchorfile>group__utility_ga9c8c29e8a2f4f5e8a663200559fdc983.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>prod</name>
      <anchorfile>group__reductions_ga8f26159ad4592d129baf258026910f98.html</anchorfile>
      <anchor>ga8f26159ad4592d129baf258026910f98</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>prod</name>
      <anchorfile>group__reductions_ga19f0d8f804838dcc33eb3456358bf96f.html</anchorfile>
      <anchor>ga19f0d8f804838dcc33eb3456358bf96f</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>push_back</name>
      <anchorfile>group__generators_ga3044bdc0eeb7425a0462c98f0e6301f1.html</anchorfile>
      <anchor>ga3044bdc0eeb7425a0462c98f0e6301f1</anchor>
      <arglist>(Tuple &amp;&amp;t, T &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>push_front</name>
      <anchorfile>group__generators_ga8f969f49a94fb50a8cb6bf27bf78b6b7.html</anchorfile>
      <anchor>ga8f969f49a94fb50a8cb6bf27bf78b6b7</anchor>
      <arglist>(Tuple &amp;&amp;t, T &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reindex</name>
      <anchorfile>group__generators_ga6a35aaac7b583b81c4c7d6dd91119f4e.html</anchorfile>
      <anchor>ga6a35aaac7b583b81c4c7d6dd91119f4e</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reorder</name>
      <anchorfile>group__generators_ga3e46e6c4fe83aeb9ce77f9002baada79.html</anchorfile>
      <anchor>ga3e46e6c4fe83aeb9ce77f9002baada79</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reorder_fields</name>
      <anchorfile>group__generators_gacacb045909983a11d31bbe8d589b0260.html</anchorfile>
      <anchor>gacacb045909983a11d31bbe8d589b0260</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reverse</name>
      <anchorfile>group__generators_ga49abf24bfdc3e6c8707cd321d9015212.html</anchorfile>
      <anchor>ga49abf24bfdc3e6c8707cd321d9015212</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>split</name>
      <anchorfile>group__generators_ga30d07f30bbfa319dfa78a9e1a5a83a38.html</anchorfile>
      <anchor>ga30d07f30bbfa319dfa78a9e1a5a83a38</anchor>
      <arglist>(Tuple &amp;&amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>sum</name>
      <anchorfile>group__reductions_gab24f978a257b3974311f19306f211d87.html</anchorfile>
      <anchor>gab24f978a257b3974311f19306f211d87</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>sum</name>
      <anchorfile>group__reductions_gafbf960e6940d260757abde26e985c878.html</anchorfile>
      <anchor>gafbf960e6940d260757abde26e985c878</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_tuple</name>
      <anchorfile>group__utility_gae6de7cdd99f5e217028b93d4bcf3de52.html</anchorfile>
      <anchor>gae6de7cdd99f5e217028b93d4bcf3de52</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>transpose</name>
      <anchorfile>group__generators_ga30ecc238fb6ffcfdf9701c80e88e498d.html</anchorfile>
      <anchor>ga30ecc238fb6ffcfdf9701c80e88e498d</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>unique</name>
      <anchorfile>group__generators_ga26131fc7a91a6860d0013d4be6151333.html</anchorfile>
      <anchor>ga26131fc7a91a6860d0013d4be6151333</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>values_of</name>
      <anchorfile>group__algorithm_ga62d44b638af9c683a8040a476518990e.html</anchorfile>
      <anchor>ga62d44b638af9c683a8040a476518990e</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>windows</name>
      <anchorfile>group__generators_ga8a3301039029674c9d9613373d282c5b.html</anchorfile>
      <anchor>ga8a3301039029674c9d9613373d282c5b</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip</name>
      <anchorfile>group__generators_ga47ba3094d9bdaeeb08ca289578710d91.html</anchorfile>
      <anchor>ga47ba3094d9bdaeeb08ca289578710d91</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_max</name>
      <anchorfile>group__generators_ga0f9c5fa8dd048452b74552e65af8978c.html</anchorfile>
      <anchor>ga0f9c5fa8dd048452b74552e65af8978c</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_min</name>
      <anchorfile>group__generators_ga4d79fad3c079dcc6714a6796b21e8177.html</anchorfile>
      <anchor>ga4d79fad3c079dcc6714a6796b21e8177</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>record</name>
      <anchorfile>group__record_gaee922438c01912318246dcd9d6a1d158.html</anchorfile>
      <anchor>gaee922438c01912318246dcd9d6a1d158</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>tie</name>
      <anchorfile>group__record_ga9b14a46ed9fd59b9f0223181f5933535.html</anchorfile>
      <anchor>ga9b14a46ed9fd59b9f0223181f5933535</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field_capture&lt; Fields, Ts &amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a58caf3f1c74614bb2224b63a6009c853</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a133ad4f00e3a029f31c6271e3cd87424</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>aaea1d0e041226d1240d798db9e362f80</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a70f3f3e1387476fc7c599d579a5ac8a2</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab01f5ed62c4842263211fe9034ba90db</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ae765fd8b37c9925ce719772a5ae2c87c</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a6707c5581367cfbec84c727143d3e6cd</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a7b4348bee4620da3ff0ecf8b85ab09a8</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac5a0cf00b5cfb30292259586591eeeae</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>af019e468726642e8de9b565ed2ed6f07</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab1d176e8cd7120c1dae77a84827bc6bf</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac7525f29a0f5dc92d21cca75ce17246f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a78a823906c703ce3cc5d7bd1a97348ab</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a592d6252de24a0bb449cd06e9edf9b73</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a848540c0c3a4cdfdf9538cfe6bea0e7c</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>tuple</name>
      <anchorfile>group__tuple_ga7e659d5e732a3a999c93d842903cb74e.html</anchorfile>
      <anchor>ga7e659d5e732a3a999c93d842903cb74e</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>tie</name>
      <anchorfile>group__tuple_ga30a5e2ccd11ad77c23e3dfd8dafcda99.html</anchorfile>
      <anchor>ga30a5e2ccd11ad77c23e3dfd8dafcda99</anchor>
      <arglist>(Ts &amp;...ts) -&gt; tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_tuple</name>
      <anchorfile>group__tuple_ga7ac66d9df58dd663395f325feb4d1b04.html</anchorfile>
      <anchor>ga7ac66d9df58dd663395f325feb4d1b04</anchor>
      <arglist>(Ts &amp;&amp;...ts) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>field</name>
      <anchorfile>group__utility_ga6a8ab73e5c1f8c0f11501e253a37f686.html</anchorfile>
      <anchor>ga6a8ab73e5c1f8c0f11501e253a37f686</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr index_t&lt; N &gt; const</type>
      <name>index</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga32a67892e5dbfb93a2292959a5a029d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_field_capture_v</name>
      <anchorfile>group__traits_ga36e654d6b1df0645cfc9854dee56fa03.html</anchorfile>
      <anchor>ga36e654d6b1df0645cfc9854dee56fa03</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_index_map_v</name>
      <anchorfile>group__traits_gab5b49ae5dceb172900933f69d976b933.html</anchorfile>
      <anchor>gab5b49ae5dceb172900933f69d976b933</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unit</type>
      <name>none</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gabe662caa7eff683f6b085c7abb76391b</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>record</name>
      <anchorfile>group__record_gaee922438c01912318246dcd9d6a1d158.html</anchorfile>
      <anchor>gaee922438c01912318246dcd9d6a1d158</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>tie</name>
      <anchorfile>group__record_ga9b14a46ed9fd59b9f0223181f5933535.html</anchorfile>
      <anchor>ga9b14a46ed9fd59b9f0223181f5933535</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field_capture&lt; Fields, Ts &amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a58caf3f1c74614bb2224b63a6009c853</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a133ad4f00e3a029f31c6271e3cd87424</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>aaea1d0e041226d1240d798db9e362f80</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a70f3f3e1387476fc7c599d579a5ac8a2</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab01f5ed62c4842263211fe9034ba90db</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ae765fd8b37c9925ce719772a5ae2c87c</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a6707c5581367cfbec84c727143d3e6cd</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a7b4348bee4620da3ff0ecf8b85ab09a8</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac5a0cf00b5cfb30292259586591eeeae</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>af019e468726642e8de9b565ed2ed6f07</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab1d176e8cd7120c1dae77a84827bc6bf</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac7525f29a0f5dc92d21cca75ce17246f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a78a823906c703ce3cc5d7bd1a97348ab</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a592d6252de24a0bb449cd06e9edf9b73</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a848540c0c3a4cdfdf9538cfe6bea0e7c</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>tuple</name>
      <anchorfile>group__tuple_ga7e659d5e732a3a999c93d842903cb74e.html</anchorfile>
      <anchor>ga7e659d5e732a3a999c93d842903cb74e</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>tie</name>
      <anchorfile>group__tuple_ga30a5e2ccd11ad77c23e3dfd8dafcda99.html</anchorfile>
      <anchor>ga30a5e2ccd11ad77c23e3dfd8dafcda99</anchor>
      <arglist>(Ts &amp;...ts) -&gt; tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_tuple</name>
      <anchorfile>group__tuple_ga7ac66d9df58dd663395f325feb4d1b04.html</anchorfile>
      <anchor>ga7ac66d9df58dd663395f325feb4d1b04</anchor>
      <arglist>(Ts &amp;&amp;...ts) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>literals</name>
    <filename>namespaceliterals.html</filename>
  </compound>
  <compound kind="group">
    <name>utility</name>
    <title>Helper Types and Functions</title>
    <filename>group__utility.html</filename>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="class">kumi::field_name</class>
    <class kind="struct">kumi::index_t</class>
    <class kind="class">kumi::indexes_t</class>
    <class kind="class">kumi::str</class>
    <class kind="class">kumi::unit</class>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::back</name>
      <anchorfile>group__utility_ga6d1e220549b74a2234e7ce58bf791d3e.html</anchorfile>
      <anchor>ga6d1e220549b74a2234e7ce58bf791d3e</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::from_tuple</name>
      <anchorfile>group__utility_gad8e73ef5a6e05c2ae2db0bcfa860de48.html</anchorfile>
      <anchor>gad8e73ef5a6e05c2ae2db0bcfa860de48</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::front</name>
      <anchorfile>group__utility_gae40b8dfe98266c4f62395c369833eef3.html</anchorfile>
      <anchor>gae40b8dfe98266c4f62395c369833eef3</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::indexes</name>
      <anchorfile>group__utility_gad9d978893c5e64520e0b0d83d133c26c.html</anchorfile>
      <anchor>gad9d978893c5e64520e0b0d83d133c26c</anchor>
      <arglist>(Ts... ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>kumi::indexes_t</name>
      <anchorfile>group__utility_gaccc36e7b78d9da78548eebf22ea28492.html</anchorfile>
      <anchor>gaccc36e7b78d9da78548eebf22ea28492</anchor>
      <arglist>(Ts...) -&gt; indexes_t&lt; Ts... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::literals::operator&quot;&quot;_c</name>
      <anchorfile>group__utility_ga60825dffaa5ee2c50e1d1a24057bdcf1.html</anchorfile>
      <anchor>ga60825dffaa5ee2c50e1d1a24057bdcf1</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::literals::operator&quot;&quot;_f</name>
      <anchorfile>group__utility_gac6640fd24bd6244cbed251ed2e689d83.html</anchorfile>
      <anchor>gac6640fd24bd6244cbed251ed2e689d83</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::predicate</name>
      <anchorfile>group__utility_ga9c8c29e8a2f4f5e8a663200559fdc983.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::to_tuple</name>
      <anchorfile>group__utility_gae6de7cdd99f5e217028b93d4bcf3de52.html</anchorfile>
      <anchor>gae6de7cdd99f5e217028b93d4bcf3de52</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>kumi::field</name>
      <anchorfile>group__utility_ga6a8ab73e5c1f8c0f11501e253a37f686.html</anchorfile>
      <anchor>ga6a8ab73e5c1f8c0f11501e253a37f686</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr index_t&lt; N &gt; const</type>
      <name>kumi::index</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga32a67892e5dbfb93a2292959a5a029d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unit</type>
      <name>kumi::none</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gabe662caa7eff683f6b085c7abb76391b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>product_types</name>
    <title>Product_types Classes</title>
    <filename>group__product__types.html</filename>
    <subgroup>record</subgroup>
    <subgroup>tuple</subgroup>
    <class kind="class">kumi::field_capture</class>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::field_capture::capture_field</name>
      <anchorfile>group__product__types_gafc8e80ba53336a0142f3267959c1ba71.html</anchorfile>
      <anchor>gafc8e80ba53336a0142f3267959c1ba71</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::field_capture::field_value_of</name>
      <anchorfile>group__product__types_gad7a01eb2dfa2f318b75141023ed56d58.html</anchorfile>
      <anchor>gad7a01eb2dfa2f318b75141023ed56d58</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::field_capture::name_of</name>
      <anchorfile>group__product__types_ga05150d8b3720e050874ad6144a164fde.html</anchorfile>
      <anchor>ga05150d8b3720e050874ad6144a164fde</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::field_capture::operator&lt;&lt;</name>
      <anchorfile>group__product__types.html</anchorfile>
      <anchor>gad9e237c94f8427a7ddfafb8fb0cc4428</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field_capture const &amp;w) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>record</name>
    <title>Record Types and Functions</title>
    <filename>group__record.html</filename>
    <class kind="class">kumi::record</class>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::record&lt; Ts... &gt;::operator&lt;&lt;</name>
      <anchorfile>group__record.html</anchorfile>
      <anchor>ga3e776cea74b6cbba98d32566764b3571</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, record const &amp;t) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>kumi::record&lt; Ts... &gt;::operator==</name>
      <anchorfile>group__record.html</anchorfile>
      <anchor>ga47cbbcecf3784722288f3391784f4ac3</anchor>
      <arglist>(record const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>kumi::record</name>
      <anchorfile>group__record_gaee922438c01912318246dcd9d6a1d158.html</anchorfile>
      <anchor>gaee922438c01912318246dcd9d6a1d158</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tie</name>
      <anchorfile>group__record_ga9b14a46ed9fd59b9f0223181f5933535.html</anchorfile>
      <anchor>ga9b14a46ed9fd59b9f0223181f5933535</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field_capture&lt; Fields, Ts &amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::record::forward_as_record</name>
      <anchorfile>group__record_ga508677aacba8fa46c42516e15c92ab3c.html</anchorfile>
      <anchor>ga508677aacba8fa46c42516e15c92ab3c</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; field_capture&lt; Fields, Ts &amp;&amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::record::make_record</name>
      <anchorfile>group__record_gae8fa9564a0714fe540bda228f2bb4001.html</anchorfile>
      <anchor>gae8fa9564a0714fe540bda228f2bb4001</anchor>
      <arglist>(Ts &amp;&amp;...ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::record::to_ref</name>
      <anchorfile>group__record_ga20a4570d5712ffff83908aab1753b614.html</anchorfile>
      <anchor>ga20a4570d5712ffff83908aab1753b614</anchor>
      <arglist>(Type &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::record::get</name>
      <anchorfile>group__record_gabc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>gabc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>algorithm</name>
    <title>Tuple Algorithms</title>
    <filename>group__algorithm.html</filename>
    <subgroup>reductions</subgroup>
    <subgroup>generators</subgroup>
    <subgroup>queries</subgroup>
    <subgroup>transforms</subgroup>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::record::get</name>
      <anchorfile>group__algorithm_ga9ae63f9221db181d1c0f0c8ff3a99b06.html</anchorfile>
      <anchor>ga9ae63f9221db181d1c0f0c8ff3a99b06</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::members_of</name>
      <anchorfile>group__algorithm_gaba7cff8d6c8c8b6d03ca78df63c9eba0.html</anchorfile>
      <anchor>gaba7cff8d6c8c8b6d03ca78df63c9eba0</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::values_of</name>
      <anchorfile>group__algorithm_ga62d44b638af9c683a8040a476518990e.html</anchorfile>
      <anchor>ga62d44b638af9c683a8040a476518990e</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>reductions</name>
    <title>Tuple Generalized Reductions</title>
    <filename>group__reductions.html</filename>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_and</name>
      <anchorfile>group__reductions_ga086ae741edfc80131295802c31e08af9.html</anchorfile>
      <anchor>ga086ae741edfc80131295802c31e08af9</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_and</name>
      <anchorfile>group__reductions_ga491ecadaaedfe84e927302683f108625.html</anchorfile>
      <anchor>ga491ecadaaedfe84e927302683f108625</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__reductions_gad66c3ad56b3536942c960c2cad1fabcf.html</anchorfile>
      <anchor>gad66c3ad56b3536942c960c2cad1fabcf</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__reductions_ga74ca2a5811c0ba2e5b0c07f6aea15d90.html</anchorfile>
      <anchor>ga74ca2a5811c0ba2e5b0c07f6aea15d90</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__reductions_gaed0714239b395a2ac14d3a6a3ec3f44c.html</anchorfile>
      <anchor>gaed0714239b395a2ac14d3a6a3ec3f44c</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__reductions_gaf5c5a77520eb5db15716f55fdb413579.html</anchorfile>
      <anchor>gaf5c5a77520eb5db15716f55fdb413579</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__reductions_ga20c7d2a3b7e7044f95ec352e64cd1b27.html</anchorfile>
      <anchor>ga20c7d2a3b7e7044f95ec352e64cd1b27</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__reductions_gaa2bdd088d82f635a5c52c6dd5bdeaaf2.html</anchorfile>
      <anchor>gaa2bdd088d82f635a5c52c6dd5bdeaaf2</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inner_product</name>
      <anchorfile>group__reductions_gaf73310d42c59ac2d79ea21586ea46265.html</anchorfile>
      <anchor>gaf73310d42c59ac2d79ea21586ea46265</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::max</name>
      <anchorfile>group__reductions_ga72159dc27be6b9aed9cc1d12ca019f28.html</anchorfile>
      <anchor>ga72159dc27be6b9aed9cc1d12ca019f28</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::max</name>
      <anchorfile>group__reductions_gae173eedc8b731830ea5df23aec9f14fa.html</anchorfile>
      <anchor>gae173eedc8b731830ea5df23aec9f14fa</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::max_flat</name>
      <anchorfile>group__reductions_gafa660a662111704882e6c9005f34f818.html</anchorfile>
      <anchor>gafa660a662111704882e6c9005f34f818</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::min</name>
      <anchorfile>group__reductions_ga2e588148a9b7eda028da7963770a5010.html</anchorfile>
      <anchor>ga2e588148a9b7eda028da7963770a5010</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::min</name>
      <anchorfile>group__reductions_gab860bed731b3d7499e9d85b1a3ce57b6.html</anchorfile>
      <anchor>gab860bed731b3d7499e9d85b1a3ce57b6</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::min_flat</name>
      <anchorfile>group__reductions_ga931f495837b8f1c878fbb8a625ca9442.html</anchorfile>
      <anchor>ga931f495837b8f1c878fbb8a625ca9442</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::prod</name>
      <anchorfile>group__reductions_ga8f26159ad4592d129baf258026910f98.html</anchorfile>
      <anchor>ga8f26159ad4592d129baf258026910f98</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::prod</name>
      <anchorfile>group__reductions_ga19f0d8f804838dcc33eb3456358bf96f.html</anchorfile>
      <anchor>ga19f0d8f804838dcc33eb3456358bf96f</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::sum</name>
      <anchorfile>group__reductions_gab24f978a257b3974311f19306f211d87.html</anchorfile>
      <anchor>gab24f978a257b3974311f19306f211d87</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::sum</name>
      <anchorfile>group__reductions_gafbf960e6940d260757abde26e985c878.html</anchorfile>
      <anchor>gafbf960e6940d260757abde26e985c878</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>generators</name>
    <title>Tuple Generators</title>
    <filename>group__generators.html</filename>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::all_unique</name>
      <anchorfile>group__generators_gacf670e19ac40c8981f52ad0783a3e483.html</anchorfile>
      <anchor>gacf670e19ac40c8981f52ad0783a3e483</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>kumi::as_flat_ptr</name>
      <anchorfile>group__generators_ga418f0a47f05b67dbb354d274dee63e4e.html</anchorfile>
      <anchor>ga418f0a47f05b67dbb354d274dee63e4e</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::cartesian_product</name>
      <anchorfile>group__generators_ga4d1776863d20d012aedf130ead1db453.html</anchorfile>
      <anchor>ga4d1776863d20d012aedf130ead1db453</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::cat</name>
      <anchorfile>group__generators_gab6e93bf9bc4d4efb456d07eb820d594e.html</anchorfile>
      <anchor>gab6e93bf9bc4d4efb456d07eb820d594e</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::chunks</name>
      <anchorfile>group__generators_ga391aae5adab10d9be8e9cbf5be4f0f64.html</anchorfile>
      <anchor>ga391aae5adab10d9be8e9cbf5be4f0f64</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::extract</name>
      <anchorfile>group__generators_ga5bafcaeb0a60662cddff54c4ca663c50.html</anchorfile>
      <anchor>ga5bafcaeb0a60662cddff54c4ca663c50</anchor>
      <arglist>(Tuple &amp;&amp;t, index_t&lt; I0 &gt; i0, index_t&lt; I1 &gt; i1) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fill</name>
      <anchorfile>group__generators_gac1f2b67c16429675ca7b9106793f9001.html</anchorfile>
      <anchor>gac1f2b67c16429675ca7b9106793f9001</anchor>
      <arglist>(T const &amp;v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::filter</name>
      <anchorfile>group__generators_ga092340ad03e4970fb79d4bc4872e4a2d.html</anchorfile>
      <anchor>ga092340ad03e4970fb79d4bc4872e4a2d</anchor>
      <arglist>(T &amp;&amp;tup) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::filter_not</name>
      <anchorfile>group__generators_gad866fde689ca139c15ddab16cd8be536.html</anchorfile>
      <anchor>gad866fde689ca139c15ddab16cd8be536</anchor>
      <arglist>(T &amp;&amp;tup) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::flatten</name>
      <anchorfile>group__generators_ga6a021e42590689a905a2d8268c860838.html</anchorfile>
      <anchor>ga6a021e42590689a905a2d8268c860838</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::flatten_all</name>
      <anchorfile>group__generators_ga5c0915917db751d43c4a07eb884945cc.html</anchorfile>
      <anchor>ga5c0915917db751d43c4a07eb884945cc</anchor>
      <arglist>(T &amp;&amp;t, Func &amp;&amp;f)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::generate</name>
      <anchorfile>group__generators_gaf6a234ed8630b3928724cf8fefbc9c6d.html</anchorfile>
      <anchor>gaf6a234ed8630b3928724cf8fefbc9c6d</anchor>
      <arglist>(Function const &amp;f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::iota</name>
      <anchorfile>group__generators_ga19ced0b66d1e3dae7bfa60f7def6914f.html</anchorfile>
      <anchor>ga19ced0b66d1e3dae7bfa60f7def6914f</anchor>
      <arglist>(T v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::partition</name>
      <anchorfile>group__generators_ga247e68735773ce448a9fc25f02d7dca0.html</anchorfile>
      <anchor>ga247e68735773ce448a9fc25f02d7dca0</anchor>
      <arglist>(T &amp;&amp;tup) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::pop_back</name>
      <anchorfile>group__generators_gaeb73a506f59ec92ddafbf7aa93fb5547.html</anchorfile>
      <anchor>gaeb73a506f59ec92ddafbf7aa93fb5547</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::pop_front</name>
      <anchorfile>group__generators_ga742995cb887d0116de190db250c3257d.html</anchorfile>
      <anchor>ga742995cb887d0116de190db250c3257d</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::push_back</name>
      <anchorfile>group__generators_ga3044bdc0eeb7425a0462c98f0e6301f1.html</anchorfile>
      <anchor>ga3044bdc0eeb7425a0462c98f0e6301f1</anchor>
      <arglist>(Tuple &amp;&amp;t, T &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::push_front</name>
      <anchorfile>group__generators_ga8f969f49a94fb50a8cb6bf27bf78b6b7.html</anchorfile>
      <anchor>ga8f969f49a94fb50a8cb6bf27bf78b6b7</anchor>
      <arglist>(Tuple &amp;&amp;t, T &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reindex</name>
      <anchorfile>group__generators_ga6a35aaac7b583b81c4c7d6dd91119f4e.html</anchorfile>
      <anchor>ga6a35aaac7b583b81c4c7d6dd91119f4e</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reorder</name>
      <anchorfile>group__generators_ga3e46e6c4fe83aeb9ce77f9002baada79.html</anchorfile>
      <anchor>ga3e46e6c4fe83aeb9ce77f9002baada79</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reorder_fields</name>
      <anchorfile>group__generators_gacacb045909983a11d31bbe8d589b0260.html</anchorfile>
      <anchor>gacacb045909983a11d31bbe8d589b0260</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reverse</name>
      <anchorfile>group__generators_ga49abf24bfdc3e6c8707cd321d9015212.html</anchorfile>
      <anchor>ga49abf24bfdc3e6c8707cd321d9015212</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::split</name>
      <anchorfile>group__generators_ga30d07f30bbfa319dfa78a9e1a5a83a38.html</anchorfile>
      <anchor>ga30d07f30bbfa319dfa78a9e1a5a83a38</anchor>
      <arglist>(Tuple &amp;&amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::transpose</name>
      <anchorfile>group__generators_ga30ecc238fb6ffcfdf9701c80e88e498d.html</anchorfile>
      <anchor>ga30ecc238fb6ffcfdf9701c80e88e498d</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::unique</name>
      <anchorfile>group__generators_ga26131fc7a91a6860d0013d4be6151333.html</anchorfile>
      <anchor>ga26131fc7a91a6860d0013d4be6151333</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::windows</name>
      <anchorfile>group__generators_ga8a3301039029674c9d9613373d282c5b.html</anchorfile>
      <anchor>ga8a3301039029674c9d9613373d282c5b</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip</name>
      <anchorfile>group__generators_ga47ba3094d9bdaeeb08ca289578710d91.html</anchorfile>
      <anchor>ga47ba3094d9bdaeeb08ca289578710d91</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_max</name>
      <anchorfile>group__generators_ga0f9c5fa8dd048452b74552e65af8978c.html</anchorfile>
      <anchor>ga0f9c5fa8dd048452b74552e65af8978c</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_min</name>
      <anchorfile>group__generators_ga4d79fad3c079dcc6714a6796b21e8177.html</anchorfile>
      <anchor>ga4d79fad3c079dcc6714a6796b21e8177</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;...ts)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>queries</name>
    <title>Tuple Queries</title>
    <filename>group__queries.html</filename>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::all_of</name>
      <anchorfile>group__queries_gabbce9eea5df0239358c6a09bf24fb667.html</anchorfile>
      <anchor>gabbce9eea5df0239358c6a09bf24fb667</anchor>
      <arglist>(T &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::all_of</name>
      <anchorfile>group__queries_ga91aebbbef8db8781c2c48bc814beed9b.html</anchorfile>
      <anchor>ga91aebbbef8db8781c2c48bc814beed9b</anchor>
      <arglist>(T &amp;&amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::any_of</name>
      <anchorfile>group__queries_ga1c7e88598454517558e84d377ff681ce.html</anchorfile>
      <anchor>ga1c7e88598454517558e84d377ff681ce</anchor>
      <arglist>(T &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::any_of</name>
      <anchorfile>group__queries_ga4564d211f8b879d1ff2b3fb1a7fa525f.html</anchorfile>
      <anchor>ga4564d211f8b879d1ff2b3fb1a7fa525f</anchor>
      <arglist>(T &amp;&amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>kumi::count</name>
      <anchorfile>group__queries_ga8f859d30f200d3a636817fb5160e342d.html</anchorfile>
      <anchor>ga8f859d30f200d3a636817fb5160e342d</anchor>
      <arglist>(T &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>kumi::count_if</name>
      <anchorfile>group__queries_gafb9e4c9675c1fccd1ba31f1b17ac1387.html</anchorfile>
      <anchor>gafb9e4c9675c1fccd1ba31f1b17ac1387</anchor>
      <arglist>(T &amp;&amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::locate</name>
      <anchorfile>group__queries_gaa67dd04ff61ae1741dd46f6a48d6ef21.html</anchorfile>
      <anchor>gaa67dd04ff61ae1741dd46f6a48d6ef21</anchor>
      <arglist>(Tuple &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::none_of</name>
      <anchorfile>group__queries_ga642ca90fe3a084caace28ee7d110ed2a.html</anchorfile>
      <anchor>ga642ca90fe3a084caace28ee7d110ed2a</anchor>
      <arglist>(Tuple &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::none_of</name>
      <anchorfile>group__queries_gac3f39b08030156afeba4800b3a527565.html</anchorfile>
      <anchor>gac3f39b08030156afeba4800b3a527565</anchor>
      <arglist>(Tuple &amp;&amp;ts, Pred p) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>concepts</name>
    <title>Tuple Related Concepts</title>
    <filename>group__concepts.html</filename>
    <concept>kumi::std_tuple_compatible</concept>
    <concept>kumi::product_type</concept>
    <concept>kumi::record_type</concept>
    <concept>kumi::sized_product_type</concept>
    <concept>kumi::sized_product_type_or_more</concept>
    <concept>kumi::empty_product_type</concept>
    <concept>kumi::non_empty_product_type</concept>
    <concept>kumi::index_map</concept>
    <concept>kumi::indexer</concept>
    <concept>kumi::homogeneous_product_type</concept>
    <concept>kumi::equality_comparable</concept>
    <concept>kumi::has_named_fields</concept>
    <concept>kumi::is_fully_named</concept>
    <concept>kumi::uniquely_typed</concept>
    <concept>kumi::uniquely_named</concept>
    <concept>kumi::entirely_uniquely_named</concept>
    <concept>kumi::contains_type</concept>
    <concept>kumi::contains_field</concept>
    <concept>kumi::equivalent</concept>
    <concept>kumi::named_equality_comparable</concept>
    <concept>kumi::follows_same_semantic</concept>
    <concept>kumi::compatible_product_types</concept>
  </compound>
  <compound kind="group">
    <name>traits</name>
    <title>Tuple Related Traits</title>
    <filename>group__traits.html</filename>
    <class kind="struct">kumi::all_unique_names</class>
    <class kind="struct">kumi::all_uniques</class>
    <class kind="struct">kumi::element</class>
    <class kind="struct">kumi::is_homogeneous</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::is_record_type</class>
    <class kind="struct">kumi::member</class>
    <class kind="struct">kumi::raw_element</class>
    <class kind="struct">kumi::raw_member</class>
    <class kind="struct">kumi::size</class>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::common_product_type</name>
      <anchorfile>group__traits_ga3226fe6731192617509a4baae1f74655.html</anchorfile>
      <anchor>ga3226fe6731192617509a4baae1f74655</anchor>
      <arglist>(Ts...)</arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_field_capture_v</name>
      <anchorfile>group__traits_ga36e654d6b1df0645cfc9854dee56fa03.html</anchorfile>
      <anchor>ga36e654d6b1df0645cfc9854dee56fa03</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>kumi::is_index_map_v</name>
      <anchorfile>group__traits_gab5b49ae5dceb172900933f69d976b933.html</anchorfile>
      <anchor>gab5b49ae5dceb172900933f69d976b933</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>transforms</name>
    <title>Tuple Transformations</title>
    <filename>group__transforms.html</filename>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::apply</name>
      <anchorfile>group__transforms_ga2c808f8956ae85b42b9b8a8ed09cc371.html</anchorfile>
      <anchor>ga2c808f8956ae85b42b9b8a8ed09cc371</anchor>
      <arglist>(Function &amp;&amp;f, Tuple &amp;&amp;t) noexcept(_::supports_nothrow_apply&lt; Function &amp;&amp;, Tuple &amp;&amp; &gt;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each</name>
      <anchorfile>group__transforms_ga1276dff11987989fc804ebe3d3804678.html</anchorfile>
      <anchor>ga1276dff11987989fc804ebe3d3804678</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_field</name>
      <anchorfile>group__transforms_ga8e05313a97d85b3fa24c9650d661db74.html</anchorfile>
      <anchor>ga8e05313a97d85b3fa24c9650d661db74</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_index</name>
      <anchorfile>group__transforms_ga39e65f96d9880dd5b1e08b8dc01993a1.html</anchorfile>
      <anchor>ga39e65f96d9880dd5b1e08b8dc01993a1</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map</name>
      <anchorfile>group__transforms_ga18c38e2efc4f46e7a4758b0aff9a46ea.html</anchorfile>
      <anchor>ga18c38e2efc4f46e7a4758b0aff9a46ea</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_field</name>
      <anchorfile>group__transforms_ga45789f4ba9e8d862296c5e6fc5178026.html</anchorfile>
      <anchor>ga45789f4ba9e8d862296c5e6fc5178026</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_index</name>
      <anchorfile>group__transforms_ga62f3925c2071557401ba32bde816e49c.html</anchorfile>
      <anchor>ga62f3925c2071557401ba32bde816e49c</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>tuple</name>
    <title>Tuple Types and Functions</title>
    <filename>group__tuple.html</filename>
    <class kind="class">kumi::_::builder</class>
    <class kind="class">kumi::tuple</class>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::tuple::operator&lt;&lt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gaf6739a069131e315597688e5b3cf5df9</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, tuple const &amp;t) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>kumi::tuple::operator==</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gaf074114f7e38446c5e298e6701e8a54b</anchor>
      <arglist>(tuple const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>kumi::tuple::operator&lt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gac0b978b3e13c057400e145cc8ac174b0</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>kumi::tuple::operator&lt;=</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>ga03b20df5887479d4b7277e30302266ea</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>kumi::tuple::operator&gt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>ga741431fe551f58d39edd28b6f6d005ae</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>kumi::tuple::operator&gt;=</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>ga6b3f89a6d6b94821ab32117291342a64</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>kumi::tuple</name>
      <anchorfile>group__tuple_ga7e659d5e732a3a999c93d842903cb74e.html</anchorfile>
      <anchor>ga7e659d5e732a3a999c93d842903cb74e</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tie</name>
      <anchorfile>group__tuple_ga30a5e2ccd11ad77c23e3dfd8dafcda99.html</anchorfile>
      <anchor>ga30a5e2ccd11ad77c23e3dfd8dafcda99</anchor>
      <arglist>(Ts &amp;...ts) -&gt; tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::make_tuple</name>
      <anchorfile>group__tuple_ga7ac66d9df58dd663395f325feb4d1b04.html</anchorfile>
      <anchor>ga7ac66d9df58dd663395f325feb4d1b04</anchor>
      <arglist>(Ts &amp;&amp;...ts) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tuple::forward_as_tuple</name>
      <anchorfile>group__tuple_ga5c5ba567f7ec305505f44bf70c67b6db.html</anchorfile>
      <anchor>ga5c5ba567f7ec305505f44bf70c67b6db</anchor>
      <arglist>(Ts &amp;&amp;...ts) -&gt; tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tuple::to_ref</name>
      <anchorfile>group__tuple_ga6cde1bebcc6150b864820645ad4cf14f.html</anchorfile>
      <anchor>ga6cde1bebcc6150b864820645ad4cf14f</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::tuple::get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>changelog</name>
    <title>Change Log</title>
    <filename>changelog.html</filename>
  </compound>
  <compound kind="page">
    <name>licence</name>
    <title>Licence</title>
    <filename>licence.html</filename>
  </compound>
  <compound kind="page">
    <name>setup</name>
    <title>Setup</title>
    <filename>setup.html</filename>
    <docanchor file="setup.html" title="Install from the source">setup-source</docanchor>
    <docanchor file="setup.html" title="Standalone setup">setup-standalone</docanchor>
    <docanchor file="setup.html" title="CMake FetchContent">setup-fetchcontent</docanchor>
    <docanchor file="setup.html" title="Setup with CPM">setup-cpm</docanchor>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>The C++20 Compact Tuple Tools</title>
    <filename>index.html</filename>
  </compound>
</tagfile>
