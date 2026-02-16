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
    <name>kumi::boolean_and</name>
    <filename>structkumi_1_1boolean__and.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1boolean__and.html</anchorfile>
      <anchor>a6c913bae350931cb94b298fa084dc4dc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::boolean_or</name>
    <filename>structkumi_1_1boolean__or.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1boolean__or.html</anchorfile>
      <anchor>a911bc467c38ab50adb4045058e5340be</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::boolean_xor</name>
    <filename>structkumi_1_1boolean__xor.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1boolean__xor.html</anchorfile>
      <anchor>a4278a7a826eea1d0843968167b7a458f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::builder</name>
    <filename>structkumi_1_1builder.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::common_product_type</name>
    <filename>structkumi_1_1common__product__type.html</filename>
    <templarg>typename... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::container_size</name>
    <filename>structkumi_1_1container__size.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::container_type</name>
    <filename>structkumi_1_1container__type.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::element</name>
    <filename>structkumi_1_1element.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::field</name>
    <filename>structkumi_1_1field.html</filename>
    <templarg>concepts::identifier Id</templarg>
    <templarg>typename T</templarg>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>name</name>
      <anchorfile>structkumi_1_1field.html</anchorfile>
      <anchor>af1f56e6cdc96a662408a06cd6e2b315d</anchor>
      <arglist>()</arglist>
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
      <name>field_cast</name>
      <anchorfile>group__product__types_ga59477c1d8542af2601f493e3320434ee.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>group__product__types.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::_::get_field_by_type</name>
    <filename>structkumi_1_1___1_1get__field__by__type.html</filename>
    <templarg>typename Ref</templarg>
    <templarg>typename... Fields</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::_::get_field_by_value&lt; Ref, std::index_sequence&lt; I... &gt;, Fields... &gt;</name>
    <filename>structkumi_1_1___1_1get__field__by__value_3_01Ref_00_01std_1_1index__sequence_3_01I_8_8_8_01_4_00_01Fields_8_8_8_01_4.html</filename>
    <templarg>typename Ref</templarg>
    <templarg>std::size_t... I</templarg>
    <templarg>typename... Fields</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::identifier</name>
    <filename>structkumi_1_1identifier.html</filename>
    <templarg>typename ID</templarg>
    <templarg>typename Checker</templarg>
    <member kind="typedef">
      <type>identifier&lt; ID, Checker &gt;</type>
      <name>tag_type</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>ac47d69746c95cdade5ce1b4ed27f420d</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>identifier</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a63367163ac0f0e4920f6eb18b2b2129e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>identifier</name>
      <anchorfile>structkumi_1_1identifier_a045670b16698c25024c8c4656bb84f0b.html</anchorfile>
      <anchor>a045670b16698c25024c8c4656bb84f0b</anchor>
      <arglist>(ID const &amp;id, Checker const &amp;chk) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr field&lt; tag_type, std::unwrap_ref_decay_t&lt; T &gt; &gt;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1identifier_ae23ea0748bbfd7baadc6e42ed92095fa.html</anchorfile>
      <anchor>ae23ea0748bbfd7baadc6e42ed92095fa</anchor>
      <arglist>(T &amp;&amp;v) const noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&lt;=&gt;</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a8b51f86f5dfec7bcd74b73f8d3c6ca65</anchor>
      <arglist>(identifier const &amp;, identifier const &amp;) noexcept=default</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a4f0c262f23a7d0530fe22387b468acb2</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, identifier const &amp;f) noexcept</arglist>
    </member>
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
    <templarg>concepts::indexer... V</templarg>
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
      <anchorfile>structkumi_1_1indexes__t_a9ca8e1559c70045f3ca0b79e16ee2c60.html</anchorfile>
      <anchor>a9ca8e1559c70045f3ca0b79e16ee2c60</anchor>
      <arglist>(indexes_t &amp;i) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>structkumi_1_1indexes__t.html</anchorfile>
      <anchor>a1f038cbf0c4bf1e11868eb6259a4371a</anchor>
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
  </compound>
  <compound kind="struct">
    <name>kumi::is_record_type</name>
    <filename>structkumi_1_1is__record__type.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename Enable</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_static_container</name>
    <filename>structkumi_1_1is__static__container.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::member</name>
    <filename>structkumi_1_1member.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::name</name>
    <filename>structkumi_1_1name.html</filename>
    <templarg>str ID</templarg>
    <member kind="function">
      <type>constexpr field&lt; tag_type, std::unwrap_ref_decay_t&lt; T &gt; &gt;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1name_a5710487fd348040031b72d88e500cd08.html</anchorfile>
      <anchor>a5710487fd348040031b72d88e500cd08</anchor>
      <arglist>(T &amp;&amp;v) const noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&lt;=&gt;</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>a77326d3a81764432b566f401b4e5fedf</anchor>
      <arglist>(name const &amp;, name const &amp;) noexcept=default</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>a7a734db1558ec830a6063ea5ad20afc6</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, name const &amp;f) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::numeric_add</name>
    <filename>structkumi_1_1numeric__add.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1numeric__add.html</anchorfile>
      <anchor>ab861a751b5a97864feb3e5241411158e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::numeric_prod</name>
    <filename>structkumi_1_1numeric__prod.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1numeric__prod.html</anchorfile>
      <anchor>a88d04ea20fb36bc95950974133d88454</anchor>
      <arglist></arglist>
    </member>
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
      <anchorfile>group__record_gab9e21ff3a58e2bcee3849abc51821c88.html</anchorfile>
      <anchor>gab9e21ff3a58e2bcee3849abc51821c88</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp;&amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_record</name>
      <anchorfile>group__record_gaaa38d1d378b716e24c974facce426d72.html</anchorfile>
      <anchor>gaaa38d1d378b716e24c974facce426d72</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__record_gabd73478b6d709990c2f81dc83b980c16.html</anchorfile>
      <anchor>gabd73478b6d709990c2f81dc83b980c16</anchor>
      <arglist>(R &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_record</name>
      <anchorfile>group__record_ga631f638102862f5ac7f8407e04eacf13.html</anchorfile>
      <anchor>ga631f638102862f5ac7f8407e04eacf13</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_record</name>
      <anchorfile>group__record_gaf3f1a7812e294e86296e09eceadbe0a3.html</anchorfile>
      <anchor>gaf3f1a7812e294e86296e09eceadbe0a3</anchor>
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
      <anchorfile>group__record_gab9e21ff3a58e2bcee3849abc51821c88.html</anchorfile>
      <anchor>gab9e21ff3a58e2bcee3849abc51821c88</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp;&amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_record</name>
      <anchorfile>group__record_gaaa38d1d378b716e24c974facce426d72.html</anchorfile>
      <anchor>gaaa38d1d378b716e24c974facce426d72</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__record_gabd73478b6d709990c2f81dc83b980c16.html</anchorfile>
      <anchor>gabd73478b6d709990c2f81dc83b980c16</anchor>
      <arglist>(R &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_record</name>
      <anchorfile>group__record_ga631f638102862f5ac7f8407e04eacf13.html</anchorfile>
      <anchor>ga631f638102862f5ac7f8407e04eacf13</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_record</name>
      <anchorfile>group__record_gaf3f1a7812e294e86296e09eceadbe0a3.html</anchorfile>
      <anchor>gaf3f1a7812e294e86296e09eceadbe0a3</anchor>
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
      <anchorfile>structkumi_1_1tuple_a0c4404dcef281e2861393df6bb517e39.html</anchorfile>
      <anchor>a0c4404dcef281e2861393df6bb517e39</anchor>
      <arglist>(index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a5960e5d8bfaaaada3245a3f153c134bd</anchor>
      <arglist>(index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8dee9f776d5da360bbcfe58d03f28e3f</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad9d54c3d6e6d1e22cf1972e2a1088a1a</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_af6bbf8ab193e8a4d8de340aa150e30dc.html</anchorfile>
      <anchor>af6bbf8ab193e8a4d8de340aa150e30dc</anchor>
      <arglist>(as&lt; T &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a0f88183ec73ad29ba6edb4a2049b3734</anchor>
      <arglist>(as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a1729c193b404ac36671f4feb4938aeeb</anchor>
      <arglist>(as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ab9e82044727515d986bda7cdc56d81ad</anchor>
      <arglist>(as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_aa181168ad020540a9d92fad032315fb6.html</anchorfile>
      <anchor>aa181168ad020540a9d92fad032315fb6</anchor>
      <arglist>(Name const &amp;n) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa60def45a7c06ec78bb88b7d66429924</anchor>
      <arglist>(Name const &amp;n) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a557d89f41ad9e5184d96974445cb6bc7</anchor>
      <arglist>(Name const &amp;n) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8d27eeb8a36b60c5e1b2d6fcc8f36688</anchor>
      <arglist>(Name const &amp;n) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cast</name>
      <anchorfile>structkumi_1_1tuple_a3967e3eb2c5a06d125fe6a68dc1c8c00.html</anchorfile>
      <anchor>a3967e3eb2c5a06d125fe6a68dc1c8c00</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple_afe7c9576494a5de1d5606fa7fcb928fc.html</anchorfile>
      <anchor>afe7c9576494a5de1d5606fa7fcb928fc</anchor>
      <arglist>(!_::piecewise_convertible&lt; tuple&lt; Ts const &amp;... &gt;, tuple&lt; Us... &gt; &gt;) const expr operator tuple&lt; Us... &gt;() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa3c4771540f6a93841aa47241275ba57</anchor>
      <arglist>(!_::piecewise_convertible&lt; tuple&lt; Ts &amp;... &gt;, tuple&lt; Us... &gt; &gt;) const expr operator tuple&lt; Us... &gt;()</arglist>
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
      <anchorfile>group__tuple_ga4cc5b452c723ee16fdd9a4de143ef0c1.html</anchorfile>
      <anchor>ga4cc5b452c723ee16fdd9a4de143ef0c1</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__tuple_ga27c29bc9a5e31d7ada4ac427a18d8985.html</anchorfile>
      <anchor>ga27c29bc9a5e31d7ada4ac427a18d8985</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_tuple</name>
      <anchorfile>group__tuple_ga5e1b1ae039b6c55ae68e875505d36774.html</anchorfile>
      <anchor>ga5e1b1ae039b6c55ae68e875505d36774</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_tuple</name>
      <anchorfile>group__tuple_gafdea058f9f804755e1b3ce010be52f40.html</anchorfile>
      <anchor>gafdea058f9f804755e1b3ce010be52f40</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
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
      <anchorfile>structkumi_1_1tuple_a0c4404dcef281e2861393df6bb517e39.html</anchorfile>
      <anchor>a0c4404dcef281e2861393df6bb517e39</anchor>
      <arglist>(index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a5960e5d8bfaaaada3245a3f153c134bd</anchor>
      <arglist>(index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8dee9f776d5da360bbcfe58d03f28e3f</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad9d54c3d6e6d1e22cf1972e2a1088a1a</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_af6bbf8ab193e8a4d8de340aa150e30dc.html</anchorfile>
      <anchor>af6bbf8ab193e8a4d8de340aa150e30dc</anchor>
      <arglist>(as&lt; T &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a0f88183ec73ad29ba6edb4a2049b3734</anchor>
      <arglist>(as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a1729c193b404ac36671f4feb4938aeeb</anchor>
      <arglist>(as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ab9e82044727515d986bda7cdc56d81ad</anchor>
      <arglist>(as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_aa181168ad020540a9d92fad032315fb6.html</anchorfile>
      <anchor>aa181168ad020540a9d92fad032315fb6</anchor>
      <arglist>(Name const &amp;n) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa60def45a7c06ec78bb88b7d66429924</anchor>
      <arglist>(Name const &amp;n) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a557d89f41ad9e5184d96974445cb6bc7</anchor>
      <arglist>(Name const &amp;n) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8d27eeb8a36b60c5e1b2d6fcc8f36688</anchor>
      <arglist>(Name const &amp;n) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cast</name>
      <anchorfile>structkumi_1_1tuple_a3967e3eb2c5a06d125fe6a68dc1c8c00.html</anchorfile>
      <anchor>a3967e3eb2c5a06d125fe6a68dc1c8c00</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple_afe7c9576494a5de1d5606fa7fcb928fc.html</anchorfile>
      <anchor>afe7c9576494a5de1d5606fa7fcb928fc</anchor>
      <arglist>(!_::piecewise_convertible&lt; tuple&lt; Ts const &amp;... &gt;, tuple&lt; Us... &gt; &gt;) const expr operator tuple&lt; Us... &gt;() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa3c4771540f6a93841aa47241275ba57</anchor>
      <arglist>(!_::piecewise_convertible&lt; tuple&lt; Ts &amp;... &gt;, tuple&lt; Us... &gt; &gt;) const expr operator tuple&lt; Us... &gt;()</arglist>
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
      <anchor>gacebb3ddeaa684e400b25f48849147641</anchor>
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
      <anchorfile>group__tuple_ga4cc5b452c723ee16fdd9a4de143ef0c1.html</anchorfile>
      <anchor>ga4cc5b452c723ee16fdd9a4de143ef0c1</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__tuple_ga27c29bc9a5e31d7ada4ac427a18d8985.html</anchorfile>
      <anchor>ga27c29bc9a5e31d7ada4ac427a18d8985</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_tuple</name>
      <anchorfile>group__tuple_ga5e1b1ae039b6c55ae68e875505d36774.html</anchorfile>
      <anchor>ga5e1b1ae039b6c55ae68e875505d36774</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_tuple</name>
      <anchorfile>group__tuple_gafdea058f9f804755e1b3ce010be52f40.html</anchorfile>
      <anchor>gafdea058f9f804755e1b3ce010be52f40</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
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
    <name>kumi::_::unique_name&lt; I, T &gt;</name>
    <filename>structkumi_1_1___1_1unique__name_3_01I_00_01T_01_4.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>_::field T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::unit</name>
    <filename>structkumi_1_1unit.html</filename>
  </compound>
  <compound kind="struct">
    <name>kumi::unknown</name>
    <filename>structkumi_1_1unknown.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::_::std_tuple_compatible</name>
    <filename>conceptkumi_1_1___1_1std__tuple__compatible.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::compatible_product_types</name>
    <filename>conceptkumi_1_1concepts_1_1compatible__product__types.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::contains_field</name>
    <filename>conceptkumi_1_1concepts_1_1contains__field.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::contains_type</name>
    <filename>conceptkumi_1_1concepts_1_1contains__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::empty_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1empty__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::entirely_uniquely_named</name>
    <filename>conceptkumi_1_1concepts_1_1entirely__uniquely__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::equality_comparable</name>
    <filename>conceptkumi_1_1concepts_1_1equality__comparable.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::equivalent</name>
    <filename>conceptkumi_1_1concepts_1_1equivalent.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::field</name>
    <filename>conceptkumi_1_1concepts_1_1field.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::follows_same_semantic</name>
    <filename>conceptkumi_1_1concepts_1_1follows__same__semantic.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::has_named_fields</name>
    <filename>conceptkumi_1_1concepts_1_1has__named__fields.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::homogeneous_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1homogeneous__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::identifier</name>
    <filename>conceptkumi_1_1concepts_1_1identifier.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::index_map</name>
    <filename>conceptkumi_1_1concepts_1_1index__map.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::indexer</name>
    <filename>conceptkumi_1_1concepts_1_1indexer.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::is_fully_named</name>
    <filename>conceptkumi_1_1concepts_1_1is__fully__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::monoid</name>
    <filename>conceptkumi_1_1concepts_1_1monoid.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::named_equality_comparable</name>
    <filename>conceptkumi_1_1concepts_1_1named__equality__comparable.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::non_empty_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1non__empty__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::product_type</name>
    <filename>conceptkumi_1_1concepts_1_1product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::record_type</name>
    <filename>conceptkumi_1_1concepts_1_1record__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::sized_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1sized__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::sized_product_type_or_more</name>
    <filename>conceptkumi_1_1concepts_1_1sized__product__type__or__more.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::static_container</name>
    <filename>conceptkumi_1_1concepts_1_1static__container.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::uniquely_named</name>
    <filename>conceptkumi_1_1concepts_1_1uniquely__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::uniquely_typed</name>
    <filename>conceptkumi_1_1concepts_1_1uniquely__typed.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::unit_type</name>
    <filename>conceptkumi_1_1concepts_1_1unit__type.html</filename>
  </compound>
  <compound kind="namespace">
    <name>kumi</name>
    <filename>namespacekumi.html</filename>
    <class kind="struct">kumi::all_unique_names</class>
    <class kind="struct">kumi::all_uniques</class>
    <class kind="class">kumi::as</class>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="class">kumi::boolean_and</class>
    <class kind="class">kumi::boolean_or</class>
    <class kind="class">kumi::boolean_xor</class>
    <class kind="class">kumi::builder</class>
    <class kind="struct">kumi::common_product_type</class>
    <class kind="struct">kumi::container_size</class>
    <class kind="struct">kumi::container_type</class>
    <class kind="struct">kumi::element</class>
    <class kind="class">kumi::field</class>
    <class kind="struct">kumi::identifier</class>
    <class kind="struct">kumi::index_t</class>
    <class kind="class">kumi::indexes_t</class>
    <class kind="struct">kumi::is_homogeneous</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::is_record_type</class>
    <class kind="struct">kumi::is_static_container</class>
    <class kind="struct">kumi::member</class>
    <class kind="struct">kumi::name</class>
    <class kind="class">kumi::numeric_add</class>
    <class kind="class">kumi::numeric_prod</class>
    <class kind="struct">kumi::raw_element</class>
    <class kind="struct">kumi::raw_member</class>
    <class kind="class">kumi::record</class>
    <class kind="struct">kumi::size</class>
    <class kind="class">kumi::str</class>
    <class kind="class">kumi::tuple</class>
    <class kind="class">kumi::unit</class>
    <class kind="struct">kumi::unknown</class>
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
      <anchorfile>group__transforms_ga570ad42b8992ce6096c05dd6b2bbcf6d.html</anchorfile>
      <anchor>ga570ad42b8992ce6096c05dd6b2bbcf6d</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t) noexcept(_::supports_nothrow_apply&lt; Function &amp;&amp;, T &amp;&amp; &gt;)</arglist>
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
      <anchorfile>group__utility_ga7847a3783c337053f6d5f53b24a2583f.html</anchorfile>
      <anchor>ga7847a3783c337053f6d5f53b24a2583f</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_and</name>
      <anchorfile>group__reductions_ga2249743d977a87399b3fd98b0cb2e55e.html</anchorfile>
      <anchor>ga2249743d977a87399b3fd98b0cb2e55e</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_and</name>
      <anchorfile>group__reductions_ga14432e4394da47b90f34c962979da853.html</anchorfile>
      <anchor>ga14432e4394da47b90f34c962979da853</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_or</name>
      <anchorfile>group__reductions_gaa7d3ae229843ffb2bbcabb1427ef4979.html</anchorfile>
      <anchor>gaa7d3ae229843ffb2bbcabb1427ef4979</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_or</name>
      <anchorfile>group__reductions_ga4b48b6259301405bba1e0944ffa6e2c7.html</anchorfile>
      <anchor>ga4b48b6259301405bba1e0944ffa6e2c7</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_xor</name>
      <anchorfile>group__reductions_ga19a1070aa59a1fd90bbf39b860058f9d.html</anchorfile>
      <anchor>ga19a1070aa59a1fd90bbf39b860058f9d</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_xor</name>
      <anchorfile>group__reductions_ga521dcc4de231768115582401a1a0419b.html</anchorfile>
      <anchor>ga521dcc4de231768115582401a1a0419b</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cartesian_product</name>
      <anchorfile>group__generators_ga0cf18e9f5c176d132be6afbfcb6652ae.html</anchorfile>
      <anchor>ga0cf18e9f5c176d132be6afbfcb6652ae</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cat</name>
      <anchorfile>group__generators_ga3786266bedb7981ba0df79cc5b49b261.html</anchorfile>
      <anchor>ga3786266bedb7981ba0df79cc5b49b261</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>chunks</name>
      <anchorfile>group__generators_ga43733ea12f98401cb32efd3e189c09b9.html</anchorfile>
      <anchor>ga43733ea12f98401cb32efd3e189c09b9</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>contains</name>
      <anchorfile>group__algorithm_ga4248deebb4632afc8082fabc051bd3cf.html</anchorfile>
      <anchor>ga4248deebb4632afc8082fabc051bd3cf</anchor>
      <arglist>(T &amp;&amp;t, K const &amp;k) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>contains_any</name>
      <anchorfile>group__algorithm_ga9642dda7a3ce929b2db63eb4c6b9c2dc.html</anchorfile>
      <anchor>ga9642dda7a3ce929b2db63eb4c6b9c2dc</anchor>
      <arglist>(T &amp;&amp;t, Ks const &amp;... ks) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>contains_none</name>
      <anchorfile>group__algorithm_ga0ee5441305b271aca61af9bcdf79f17c.html</anchorfile>
      <anchor>ga0ee5441305b271aca61af9bcdf79f17c</anchor>
      <arglist>(T &amp;&amp;t, Ks const &amp;... ks) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>contains_only</name>
      <anchorfile>group__algorithm_ga1a33ca63675587c5adbaa0f73a54f498.html</anchorfile>
      <anchor>ga1a33ca63675587c5adbaa0f73a54f498</anchor>
      <arglist>(T &amp;&amp;t, Ks const &amp;... ks) noexcept</arglist>
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
      <name>exclusive_scan_left</name>
      <anchorfile>group__reductions_gae113f4baf3a17cc22dac25df57c06031.html</anchorfile>
      <anchor>gae113f4baf3a17cc22dac25df57c06031</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>exclusive_scan_left</name>
      <anchorfile>group__reductions_ga3cba3a0d02a465184302a59f4d05bc89.html</anchorfile>
      <anchor>ga3cba3a0d02a465184302a59f4d05bc89</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>exclusive_scan_right</name>
      <anchorfile>group__reductions_gae9b0c7f1e3d7ecc8463c7275dfad5078.html</anchorfile>
      <anchor>gae9b0c7f1e3d7ecc8463c7275dfad5078</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>exclusive_scan_right</name>
      <anchorfile>group__reductions_ga33f26f28d0909a45b8e2e62b39a8bf4e.html</anchorfile>
      <anchor>ga33f26f28d0909a45b8e2e62b39a8bf4e</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>extract</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a18196956d8b3402f081b5ec0ae41cbfd</anchor>
      <arglist>(Tuple &amp;&amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>extract</name>
      <anchorfile>group__generators_ga3b4519e0786eb3e74149c04e13a286c3.html</anchorfile>
      <anchor>ga3b4519e0786eb3e74149c04e13a286c3</anchor>
      <arglist>(Tuple &amp;&amp;t, index_t&lt; I0 &gt; i0, index_t&lt; I1 &gt; i1) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>field_value_of</name>
      <anchorfile>group__utility_gabf2013046cf8ec8ac781128a815709cc.html</anchorfile>
      <anchor>gabf2013046cf8ec8ac781128a815709cc</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
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
      <anchorfile>group__generators_gaafed5030f3115f8fda5f1966a9fdfd38.html</anchorfile>
      <anchor>gaafed5030f3115f8fda5f1966a9fdfd38</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>filter_not</name>
      <anchorfile>group__generators_ga4252a5ff33d90265f42d4b6c70e48bed.html</anchorfile>
      <anchor>ga4252a5ff33d90265f42d4b6c70e48bed</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
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
      <anchorfile>group__generators_ga7416f4db26c4e41360e71dd449de20a6.html</anchorfile>
      <anchor>ga7416f4db26c4e41360e71dd449de20a6</anchor>
      <arglist>(T &amp;&amp;t, Func f)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_left</name>
      <anchorfile>group__reductions_ga74e253f7967cc7f188a979551cf687ef.html</anchorfile>
      <anchor>ga74e253f7967cc7f188a979551cf687ef</anchor>
      <arglist>(Function f, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_left</name>
      <anchorfile>group__reductions_ga0f786372596b4dd7b924bf944871d7ad.html</anchorfile>
      <anchor>ga0f786372596b4dd7b924bf944871d7ad</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_right</name>
      <anchorfile>group__reductions_ga0f30eadf94cf474e9e54f4b6d495f4c6.html</anchorfile>
      <anchor>ga0f30eadf94cf474e9e54f4b6d495f4c6</anchor>
      <arglist>(Function f, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_right</name>
      <anchorfile>group__reductions_ga5842a04c6880086a9fb8f3a06bc81469.html</anchorfile>
      <anchor>ga5842a04c6880086a9fb8f3a06bc81469</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each</name>
      <anchorfile>group__transforms_gacfc6eb17686b7570f768de71198d8812.html</anchorfile>
      <anchor>gacfc6eb17686b7570f768de71198d8812</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_field</name>
      <anchorfile>group__transforms_gab51ac1793c12bbc1b1979bc0b51eb33a.html</anchorfile>
      <anchor>gab51ac1793c12bbc1b1979bc0b51eb33a</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_index</name>
      <anchorfile>group__transforms_ga1e4f9df80b8d396b32e2f5d3316caea9.html</anchorfile>
      <anchor>ga1e4f9df80b8d396b32e2f5d3316caea9</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>front</name>
      <anchorfile>group__utility_ga0a86710de48273efa390a88ba18b2017.html</anchorfile>
      <anchor>ga0a86710de48273efa390a88ba18b2017</anchor>
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
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a3bed04b26cba84bd2546324ac23c8d5b</anchor>
      <arglist>(R &amp;&amp;r)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a58627d6a1308a26a3f8bffba4ff53434</anchor>
      <arglist>(R &amp;&amp;r)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a132150f11383e0fbe65569de5606e178</anchor>
      <arglist>(R &amp;&amp;r)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a596065b1ef152416c27785e787a6de04</anchor>
      <arglist>(R &amp;&amp;r)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi_a5a398ee0362752194bc85fde7f9fd01d.html</anchorfile>
      <anchor>a5a398ee0362752194bc85fde7f9fd01d</anchor>
      <arglist>(T &amp;&amp;r)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi_aa8f9fbb25b1821780fa1fd523c09d083.html</anchorfile>
      <anchor>aa8f9fbb25b1821780fa1fd523c09d083</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi_a8642711b7ee9134eb4e2fc8d79acb0de.html</anchorfile>
      <anchor>a8642711b7ee9134eb4e2fc8d79acb0de</anchor>
      <arglist>(T &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi_ac8926a67aa3f403e053a5c30b47e5d40.html</anchorfile>
      <anchor>ac8926a67aa3f403e053a5c30b47e5d40</anchor>
      <arglist>(T &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi_a67573177dba883247839bacf6dcb7df9.html</anchorfile>
      <anchor>a67573177dba883247839bacf6dcb7df9</anchor>
      <arglist>(T &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inclusive_scan_left</name>
      <anchorfile>group__reductions_gab62658d582fe17a5824465ba5e669b26.html</anchorfile>
      <anchor>gab62658d582fe17a5824465ba5e669b26</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inclusive_scan_left</name>
      <anchorfile>group__reductions_ga18e1921f3f9aeb30ed0edf8ec9371577.html</anchorfile>
      <anchor>ga18e1921f3f9aeb30ed0edf8ec9371577</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inclusive_scan_right</name>
      <anchorfile>group__reductions_gaa626c4c72c6c4f6ac575851c0dbf06bb.html</anchorfile>
      <anchor>gaa626c4c72c6c4f6ac575851c0dbf06bb</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inclusive_scan_right</name>
      <anchorfile>group__reductions_ga12e5013494b9498224e311c8cf51a76c.html</anchorfile>
      <anchor>ga12e5013494b9498224e311c8cf51a76c</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
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
      <anchor>aecc2a0ba7a4f6dce228e0c5181889668</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>group__reductions_gae9e0f77ffe8399c701ba32532db19d11.html</anchorfile>
      <anchor>gae9e0f77ffe8399c701ba32532db19d11</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>invoke</name>
      <anchorfile>group__utility_gab575cbbe8a1b85d03353f65128d351ac.html</anchorfile>
      <anchor>gab575cbbe8a1b85d03353f65128d351ac</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable&lt; C, Ts... &gt;::value)</arglist>
    </member>
    <member kind="function">
      <type>constexpr R</type>
      <name>invoke_r</name>
      <anchorfile>group__utility_ga81fb4720ada9b1bff437c3340fcc98b0.html</anchorfile>
      <anchor>ga81fb4720ada9b1bff437c3340fcc98b0</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_r&lt; R, C, Ts... &gt;::value)</arglist>
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
      <anchorfile>group__transforms_ga5fb0d0c6af4d4c1a814e5bf746f8201a.html</anchorfile>
      <anchor>ga5fb0d0c6af4d4c1a814e5bf746f8201a</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_field</name>
      <anchorfile>group__transforms_ga2096ba88ea732e93bd9025952ae1f9f2.html</anchorfile>
      <anchor>ga2096ba88ea732e93bd9025952ae1f9f2</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_index</name>
      <anchorfile>group__transforms_ga3860b86e65fdb667cb114f575fe3eb75.html</anchorfile>
      <anchor>ga3860b86e65fdb667cb114f575fe3eb75</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_reduce</name>
      <anchorfile>group__reductions_gace3f0fb4e67066f6f82052efd359b2b4.html</anchorfile>
      <anchor>gace3f0fb4e67066f6f82052efd359b2b4</anchor>
      <arglist>(Function f, M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_reduce</name>
      <anchorfile>group__reductions_gaa6b16ddb18150ef85f789e80593b68a2.html</anchorfile>
      <anchor>gaa6b16ddb18150ef85f789e80593b68a2</anchor>
      <arglist>(Function f, M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
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
      <name>member_cast</name>
      <anchorfile>group__utility_ga79787185d26368946a74f31ce5f6597c.html</anchorfile>
      <anchor>ga79787185d26368946a74f31ce5f6597c</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
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
      <type>constexpr auto</type>
      <name>name_of</name>
      <anchorfile>group__utility_ga8242e5044e75e129a3e87f23325eba01.html</anchorfile>
      <anchor>ga8242e5044e75e129a3e87f23325eba01</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
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
      <name>operator&quot;&quot;_id</name>
      <anchorfile>group__utility_ga10f2338fc8867a50a4295325873f3de4.html</anchorfile>
      <anchor>ga10f2338fc8867a50a4295325873f3de4</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>partition</name>
      <anchorfile>group__generators_gaf7926aecf07b881c2005e39f34512851.html</anchorfile>
      <anchor>gaf7926aecf07b881c2005e39f34512851</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
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
      <anchorfile>group__reductions_ga9c9775c7c76aebd9db20d0e44eec6034.html</anchorfile>
      <anchor>ga9c9775c7c76aebd9db20d0e44eec6034</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>prod</name>
      <anchorfile>group__reductions_gad87f59b6ce034ee52f7bf15e67cf7450.html</anchorfile>
      <anchor>gad87f59b6ce034ee52f7bf15e67cf7450</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
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
      <name>reduce</name>
      <anchorfile>group__reductions_ga812fe60401e985cc2ebd067bc42f0354.html</anchorfile>
      <anchor>ga812fe60401e985cc2ebd067bc42f0354</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reduce</name>
      <anchorfile>group__reductions_ga7d1398c56521f65375bb2f2b28e945cb.html</anchorfile>
      <anchor>ga7d1398c56521f65375bb2f2b28e945cb</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reindex</name>
      <anchorfile>group__generators_ga18d76245ac67494ea0fe64d5a3c39bc3.html</anchorfile>
      <anchor>ga18d76245ac67494ea0fe64d5a3c39bc3</anchor>
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
      <anchorfile>group__generators_ga09d177328c5c5e6c43e994048236a1d6.html</anchorfile>
      <anchor>ga09d177328c5c5e6c43e994048236a1d6</anchor>
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
      <name>rotate_left</name>
      <anchorfile>group__generators_ga969f4ebe05e88580436080ab956e7e37.html</anchorfile>
      <anchor>ga969f4ebe05e88580436080ab956e7e37</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>rotate_right</name>
      <anchorfile>group__generators_ga7b4c54857ff1b5253b86ae9b05098268.html</anchorfile>
      <anchor>ga7b4c54857ff1b5253b86ae9b05098268</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
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
      <anchorfile>group__reductions_gaa96dfd76fe746fe28e1a833ad76c59fc.html</anchorfile>
      <anchor>gaa96dfd76fe746fe28e1a833ad76c59fc</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>sum</name>
      <anchorfile>group__reductions_ga183fa966de706e5e6c78a9cc50202fe8.html</anchorfile>
      <anchor>ga183fa966de706e5e6c78a9cc50202fe8</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>transpose</name>
      <anchorfile>group__generators_ga50bbffc3a4571932d98ffe63499971dd.html</anchorfile>
      <anchor>ga50bbffc3a4571932d98ffe63499971dd</anchor>
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
      <anchorfile>group__generators_ga733dfa174c0e531632cc1b0dd433a593.html</anchorfile>
      <anchor>ga733dfa174c0e531632cc1b0dd433a593</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip</name>
      <anchorfile>group__generators_ga6fcdd03f2a3360cbb976cf05e0b0468c.html</anchorfile>
      <anchor>ga6fcdd03f2a3360cbb976cf05e0b0468c</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_max</name>
      <anchorfile>group__generators_gad2b81bc979a4089affddfdbef866e80b.html</anchorfile>
      <anchor>gad2b81bc979a4089affddfdbef866e80b</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_min</name>
      <anchorfile>group__generators_ga90d498013e5f387b2c906a4184644979.html</anchorfile>
      <anchor>ga90d498013e5f387b2c906a4184644979</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
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
      <anchorfile>group__record_gac9a691cb30072f994a527e13b861522e.html</anchorfile>
      <anchor>gac9a691cb30072f994a527e13b861522e</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>abd1d4a59b0cddc9d5a5aef185c9f1e46</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a8fef7919e4c117f76d36a950bcf767be</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac6fc9fce7bdde16b5271628195902871</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5d510d20af1d864ce25ad136fbb467e9</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a525b9bf94e60ea3d630e6de36a42f133</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>aaf022167f51842c613401859d5f7578c</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a307812e306a7b5c202ed1798fb62a381</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a8117ba9d0408fbf57fd945ecebcf88e0</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>af12d0b680d84fb4fa3e6b2cf561cf513</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a9de264085d61cff2b0ddebd38510481f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac4fd10ae8604dc8f891d7f4717dfa57e</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a954663e8f00c7c0cd39b2c70b78a8f21</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>af75adc373689cd5267452785087fe622</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab541531bd73557e4fac46218edfc39eb</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a89012f34fbafd67457ccee42b32009d4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac15f1974d785bdc3d11acaa12379c851</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a42f6cb2982d4374c8bf3d46c4290fbda</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a59669e7698120aa9bf0b5abb7870628f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a2342cf3de3692f9b9d0660dd1dc81762</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ae3f1c4953ff0f9131424f6ac8e2cca53</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5b2bcea0c243bc1bc599a4f3c80911fa</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a39ecd46d106c6dbd4e62cebd364bdc9e</anchor>
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
      <anchorfile>group__tuple_ga1a3be7d170cb81c6f87c93a0a04eabc8.html</anchorfile>
      <anchor>ga1a3be7d170cb81c6f87c93a0a04eabc8</anchor>
      <arglist>(Ts &amp;... ts) -&gt; tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_tuple</name>
      <anchorfile>group__tuple_ga98e6c367de0e0f526565280a0856b007.html</anchorfile>
      <anchor>ga98e6c367de0e0f526565280a0856b007</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="variable">
      <type>constexpr traits_check&lt; Traits &gt;</type>
      <name>if_</name>
      <anchorfile>group__utility_gacadc026868e6654e80c57432643c804a.html</anchorfile>
      <anchor>gacadc026868e6654e80c57432643c804a</anchor>
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
    <member kind="variable">
      <type>constexpr only_t&lt; T &gt;</type>
      <name>only</name>
      <anchorfile>group__utility_ga6a8e75139bc622fbedae986420916d98.html</anchorfile>
      <anchor>ga6a8e75139bc622fbedae986420916d98</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_tuple</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a74db3542e4e4c5fab79b01cda617d964</anchor>
      <arglist>(S &amp;&amp;s)</arglist>
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
      <anchorfile>group__record_gac9a691cb30072f994a527e13b861522e.html</anchorfile>
      <anchor>gac9a691cb30072f994a527e13b861522e</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>abd1d4a59b0cddc9d5a5aef185c9f1e46</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a8fef7919e4c117f76d36a950bcf767be</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac6fc9fce7bdde16b5271628195902871</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5d510d20af1d864ce25ad136fbb467e9</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a525b9bf94e60ea3d630e6de36a42f133</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>aaf022167f51842c613401859d5f7578c</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a307812e306a7b5c202ed1798fb62a381</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a8117ba9d0408fbf57fd945ecebcf88e0</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>af12d0b680d84fb4fa3e6b2cf561cf513</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a9de264085d61cff2b0ddebd38510481f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac4fd10ae8604dc8f891d7f4717dfa57e</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a954663e8f00c7c0cd39b2c70b78a8f21</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>af75adc373689cd5267452785087fe622</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab541531bd73557e4fac46218edfc39eb</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a89012f34fbafd67457ccee42b32009d4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ac15f1974d785bdc3d11acaa12379c851</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a42f6cb2982d4374c8bf3d46c4290fbda</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a59669e7698120aa9bf0b5abb7870628f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a2342cf3de3692f9b9d0660dd1dc81762</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ae3f1c4953ff0f9131424f6ac8e2cca53</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5b2bcea0c243bc1bc599a4f3c80911fa</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a39ecd46d106c6dbd4e62cebd364bdc9e</anchor>
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
      <anchorfile>group__tuple_ga1a3be7d170cb81c6f87c93a0a04eabc8.html</anchorfile>
      <anchor>ga1a3be7d170cb81c6f87c93a0a04eabc8</anchor>
      <arglist>(Ts &amp;... ts) -&gt; tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_tuple</name>
      <anchorfile>group__tuple_ga98e6c367de0e0f526565280a0856b007.html</anchorfile>
      <anchor>ga98e6c367de0e0f526565280a0856b007</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>literals</name>
    <filename>namespaceliterals.html</filename>
  </compound>
  <compound kind="group">
    <name>details</name>
    <title>Helper Types and Functions</title>
    <filename>group__details.html</filename>
  </compound>
  <compound kind="group">
    <name>utility</name>
    <title>Helper Types and Functions</title>
    <filename>group__utility.html</filename>
    <class kind="class">kumi::boolean_and</class>
    <class kind="class">kumi::boolean_or</class>
    <class kind="class">kumi::boolean_xor</class>
    <class kind="class">kumi::builder</class>
    <class kind="struct">kumi::identifier</class>
    <class kind="struct">kumi::index_t</class>
    <class kind="class">kumi::indexes_t</class>
    <class kind="struct">kumi::name</class>
    <class kind="class">kumi::numeric_add</class>
    <class kind="class">kumi::numeric_prod</class>
    <class kind="class">kumi::str</class>
    <class kind="class">kumi::unit</class>
    <class kind="struct">kumi::unknown</class>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::back</name>
      <anchorfile>group__utility_ga7847a3783c337053f6d5f53b24a2583f.html</anchorfile>
      <anchor>ga7847a3783c337053f6d5f53b24a2583f</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::field_value_of</name>
      <anchorfile>group__utility_gabf2013046cf8ec8ac781128a815709cc.html</anchorfile>
      <anchor>gabf2013046cf8ec8ac781128a815709cc</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::front</name>
      <anchorfile>group__utility_ga0a86710de48273efa390a88ba18b2017.html</anchorfile>
      <anchor>ga0a86710de48273efa390a88ba18b2017</anchor>
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
      <type>constexpr decltype(auto)</type>
      <name>kumi::invoke</name>
      <anchorfile>group__utility_gab575cbbe8a1b85d03353f65128d351ac.html</anchorfile>
      <anchor>gab575cbbe8a1b85d03353f65128d351ac</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable&lt; C, Ts... &gt;::value)</arglist>
    </member>
    <member kind="function">
      <type>constexpr R</type>
      <name>kumi::invoke_r</name>
      <anchorfile>group__utility_ga81fb4720ada9b1bff437c3340fcc98b0.html</anchorfile>
      <anchor>ga81fb4720ada9b1bff437c3340fcc98b0</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_r&lt; R, C, Ts... &gt;::value)</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>kumi::_::make_streamable</name>
      <anchorfile>group__utility_ga887c8b81e291a506cd119c794ca4b727.html</anchorfile>
      <anchor>ga887c8b81e291a506cd119c794ca4b727</anchor>
      <arglist>(T const &amp;e)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::member_cast</name>
      <anchorfile>group__utility_ga79787185d26368946a74f31ce5f6597c.html</anchorfile>
      <anchor>ga79787185d26368946a74f31ce5f6597c</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::name_of</name>
      <anchorfile>group__utility_ga8242e5044e75e129a3e87f23325eba01.html</anchorfile>
      <anchor>ga8242e5044e75e129a3e87f23325eba01</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
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
      <name>kumi::literals::operator&quot;&quot;_id</name>
      <anchorfile>group__utility_ga10f2338fc8867a50a4295325873f3de4.html</anchorfile>
      <anchor>ga10f2338fc8867a50a4295325873f3de4</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::predicate</name>
      <anchorfile>group__utility_ga9c8c29e8a2f4f5e8a663200559fdc983.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="variable">
      <type>constexpr boolean_and</type>
      <name>kumi::function::bit_and</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gaa04ecc72014400d45d9ebb72bd7447cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr boolean_or</type>
      <name>kumi::function::bit_or</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gac095643bedb84ce2b3fdf1bd0c4a9cc3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr boolean_xor</type>
      <name>kumi::function::bit_xor</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gac2d793601af17db10563acf07dc1a29f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr traits_check&lt; Traits &gt;</type>
      <name>kumi::if_</name>
      <anchorfile>group__utility_gacadc026868e6654e80c57432643c804a.html</anchorfile>
      <anchor>gacadc026868e6654e80c57432643c804a</anchor>
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
      <type>constexpr numeric_prod</type>
      <name>kumi::function::multiplies</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gaaab79e5ddd9913e237c23b6ebbe0d274</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unit</type>
      <name>kumi::none</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gabe662caa7eff683f6b085c7abb76391b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr only_t&lt; T &gt;</type>
      <name>kumi::only</name>
      <anchorfile>group__utility_ga6a8e75139bc622fbedae986420916d98.html</anchorfile>
      <anchor>ga6a8e75139bc622fbedae986420916d98</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr numeric_add</type>
      <name>kumi::function::plus</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gab5c0eb8022e7b2df33286d9a15247559</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>product_types</name>
    <title>Product_types Classes</title>
    <filename>group__product__types.html</filename>
    <subgroup>record</subgroup>
    <subgroup>tuple</subgroup>
    <class kind="class">kumi::field</class>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::field::capture_field</name>
      <anchorfile>group__product__types_gafc8e80ba53336a0142f3267959c1ba71.html</anchorfile>
      <anchor>gafc8e80ba53336a0142f3267959c1ba71</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::field::field_cast</name>
      <anchorfile>group__product__types_ga59477c1d8542af2601f493e3320434ee.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::field::operator&lt;&lt;</name>
      <anchorfile>group__product__types.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::field&lt; Id, T &gt;::operator&lt;&lt;</name>
      <anchorfile>group__product__types.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
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
      <anchor>ga451ebda777651647641516bddd22e1b1</anchor>
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
      <anchorfile>group__record_gac9a691cb30072f994a527e13b861522e.html</anchorfile>
      <anchor>gac9a691cb30072f994a527e13b861522e</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::record::forward_as_record</name>
      <anchorfile>group__record_gab9e21ff3a58e2bcee3849abc51821c88.html</anchorfile>
      <anchor>gab9e21ff3a58e2bcee3849abc51821c88</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp;&amp; &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::record::make_record</name>
      <anchorfile>group__record_gaaa38d1d378b716e24c974facce426d72.html</anchorfile>
      <anchor>gaaa38d1d378b716e24c974facce426d72</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::record::to_ref</name>
      <anchorfile>group__record_gabd73478b6d709990c2f81dc83b980c16.html</anchorfile>
      <anchor>gabd73478b6d709990c2f81dc83b980c16</anchor>
      <arglist>(R &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::record::from_record</name>
      <anchorfile>group__record_ga631f638102862f5ac7f8407e04eacf13.html</anchorfile>
      <anchor>ga631f638102862f5ac7f8407e04eacf13</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::record::to_record</name>
      <anchorfile>group__record_gaf3f1a7812e294e86296e09eceadbe0a3.html</anchorfile>
      <anchor>gaf3f1a7812e294e86296e09eceadbe0a3</anchor>
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
      <type>constexpr bool</type>
      <name>kumi::contains</name>
      <anchorfile>group__algorithm_ga4248deebb4632afc8082fabc051bd3cf.html</anchorfile>
      <anchor>ga4248deebb4632afc8082fabc051bd3cf</anchor>
      <arglist>(T &amp;&amp;t, K const &amp;k) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::contains_any</name>
      <anchorfile>group__algorithm_ga9642dda7a3ce929b2db63eb4c6b9c2dc.html</anchorfile>
      <anchor>ga9642dda7a3ce929b2db63eb4c6b9c2dc</anchor>
      <arglist>(T &amp;&amp;t, Ks const &amp;... ks) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::contains_none</name>
      <anchorfile>group__algorithm_ga0ee5441305b271aca61af9bcdf79f17c.html</anchorfile>
      <anchor>ga0ee5441305b271aca61af9bcdf79f17c</anchor>
      <arglist>(T &amp;&amp;t, Ks const &amp;... ks) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::contains_only</name>
      <anchorfile>group__algorithm_ga1a33ca63675587c5adbaa0f73a54f498.html</anchorfile>
      <anchor>ga1a33ca63675587c5adbaa0f73a54f498</anchor>
      <arglist>(T &amp;&amp;t, Ks const &amp;... ks) noexcept</arglist>
    </member>
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
      <anchorfile>group__reductions_ga2249743d977a87399b3fd98b0cb2e55e.html</anchorfile>
      <anchor>ga2249743d977a87399b3fd98b0cb2e55e</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_and</name>
      <anchorfile>group__reductions_ga14432e4394da47b90f34c962979da853.html</anchorfile>
      <anchor>ga14432e4394da47b90f34c962979da853</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__reductions_gaa7d3ae229843ffb2bbcabb1427ef4979.html</anchorfile>
      <anchor>gaa7d3ae229843ffb2bbcabb1427ef4979</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__reductions_ga4b48b6259301405bba1e0944ffa6e2c7.html</anchorfile>
      <anchor>ga4b48b6259301405bba1e0944ffa6e2c7</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_xor</name>
      <anchorfile>group__reductions_ga19a1070aa59a1fd90bbf39b860058f9d.html</anchorfile>
      <anchor>ga19a1070aa59a1fd90bbf39b860058f9d</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_xor</name>
      <anchorfile>group__reductions_ga521dcc4de231768115582401a1a0419b.html</anchorfile>
      <anchor>ga521dcc4de231768115582401a1a0419b</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::exclusive_scan_left</name>
      <anchorfile>group__reductions_gae113f4baf3a17cc22dac25df57c06031.html</anchorfile>
      <anchor>gae113f4baf3a17cc22dac25df57c06031</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::exclusive_scan_left</name>
      <anchorfile>group__reductions_ga3cba3a0d02a465184302a59f4d05bc89.html</anchorfile>
      <anchor>ga3cba3a0d02a465184302a59f4d05bc89</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::exclusive_scan_right</name>
      <anchorfile>group__reductions_gae9b0c7f1e3d7ecc8463c7275dfad5078.html</anchorfile>
      <anchor>gae9b0c7f1e3d7ecc8463c7275dfad5078</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::exclusive_scan_right</name>
      <anchorfile>group__reductions_ga33f26f28d0909a45b8e2e62b39a8bf4e.html</anchorfile>
      <anchor>ga33f26f28d0909a45b8e2e62b39a8bf4e</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__reductions_ga74e253f7967cc7f188a979551cf687ef.html</anchorfile>
      <anchor>ga74e253f7967cc7f188a979551cf687ef</anchor>
      <arglist>(Function f, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__reductions_ga0f786372596b4dd7b924bf944871d7ad.html</anchorfile>
      <anchor>ga0f786372596b4dd7b924bf944871d7ad</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__reductions_ga0f30eadf94cf474e9e54f4b6d495f4c6.html</anchorfile>
      <anchor>ga0f30eadf94cf474e9e54f4b6d495f4c6</anchor>
      <arglist>(Function f, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__reductions_ga5842a04c6880086a9fb8f3a06bc81469.html</anchorfile>
      <anchor>ga5842a04c6880086a9fb8f3a06bc81469</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inclusive_scan_left</name>
      <anchorfile>group__reductions_gab62658d582fe17a5824465ba5e669b26.html</anchorfile>
      <anchor>gab62658d582fe17a5824465ba5e669b26</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inclusive_scan_left</name>
      <anchorfile>group__reductions_ga18e1921f3f9aeb30ed0edf8ec9371577.html</anchorfile>
      <anchor>ga18e1921f3f9aeb30ed0edf8ec9371577</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inclusive_scan_right</name>
      <anchorfile>group__reductions_gaa626c4c72c6c4f6ac575851c0dbf06bb.html</anchorfile>
      <anchor>gaa626c4c72c6c4f6ac575851c0dbf06bb</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inclusive_scan_right</name>
      <anchorfile>group__reductions_ga12e5013494b9498224e311c8cf51a76c.html</anchorfile>
      <anchor>ga12e5013494b9498224e311c8cf51a76c</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inner_product</name>
      <anchorfile>group__reductions_gae9e0f77ffe8399c701ba32532db19d11.html</anchorfile>
      <anchor>gae9e0f77ffe8399c701ba32532db19d11</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_reduce</name>
      <anchorfile>group__reductions_gace3f0fb4e67066f6f82052efd359b2b4.html</anchorfile>
      <anchor>gace3f0fb4e67066f6f82052efd359b2b4</anchor>
      <arglist>(Function f, M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_reduce</name>
      <anchorfile>group__reductions_gaa6b16ddb18150ef85f789e80593b68a2.html</anchorfile>
      <anchor>gaa6b16ddb18150ef85f789e80593b68a2</anchor>
      <arglist>(Function f, M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__reductions_ga9c9775c7c76aebd9db20d0e44eec6034.html</anchorfile>
      <anchor>ga9c9775c7c76aebd9db20d0e44eec6034</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::prod</name>
      <anchorfile>group__reductions_gad87f59b6ce034ee52f7bf15e67cf7450.html</anchorfile>
      <anchor>gad87f59b6ce034ee52f7bf15e67cf7450</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reduce</name>
      <anchorfile>group__reductions_ga812fe60401e985cc2ebd067bc42f0354.html</anchorfile>
      <anchor>ga812fe60401e985cc2ebd067bc42f0354</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reduce</name>
      <anchorfile>group__reductions_ga7d1398c56521f65375bb2f2b28e945cb.html</anchorfile>
      <anchor>ga7d1398c56521f65375bb2f2b28e945cb</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::sum</name>
      <anchorfile>group__reductions_gaa96dfd76fe746fe28e1a833ad76c59fc.html</anchorfile>
      <anchor>gaa96dfd76fe746fe28e1a833ad76c59fc</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::sum</name>
      <anchorfile>group__reductions_ga183fa966de706e5e6c78a9cc50202fe8.html</anchorfile>
      <anchor>ga183fa966de706e5e6c78a9cc50202fe8</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__generators_ga0cf18e9f5c176d132be6afbfcb6652ae.html</anchorfile>
      <anchor>ga0cf18e9f5c176d132be6afbfcb6652ae</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::cat</name>
      <anchorfile>group__generators_ga3786266bedb7981ba0df79cc5b49b261.html</anchorfile>
      <anchor>ga3786266bedb7981ba0df79cc5b49b261</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::chunks</name>
      <anchorfile>group__generators_ga43733ea12f98401cb32efd3e189c09b9.html</anchorfile>
      <anchor>ga43733ea12f98401cb32efd3e189c09b9</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::extract</name>
      <anchorfile>group__generators_ga3b4519e0786eb3e74149c04e13a286c3.html</anchorfile>
      <anchor>ga3b4519e0786eb3e74149c04e13a286c3</anchor>
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
      <anchorfile>group__generators_gaafed5030f3115f8fda5f1966a9fdfd38.html</anchorfile>
      <anchor>gaafed5030f3115f8fda5f1966a9fdfd38</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::filter_not</name>
      <anchorfile>group__generators_ga4252a5ff33d90265f42d4b6c70e48bed.html</anchorfile>
      <anchor>ga4252a5ff33d90265f42d4b6c70e48bed</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
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
      <anchorfile>group__generators_ga7416f4db26c4e41360e71dd449de20a6.html</anchorfile>
      <anchor>ga7416f4db26c4e41360e71dd449de20a6</anchor>
      <arglist>(T &amp;&amp;t, Func f)</arglist>
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
      <anchorfile>group__generators_gaf7926aecf07b881c2005e39f34512851.html</anchorfile>
      <anchor>gaf7926aecf07b881c2005e39f34512851</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
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
      <anchorfile>group__generators_ga18d76245ac67494ea0fe64d5a3c39bc3.html</anchorfile>
      <anchor>ga18d76245ac67494ea0fe64d5a3c39bc3</anchor>
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
      <anchorfile>group__generators_ga09d177328c5c5e6c43e994048236a1d6.html</anchorfile>
      <anchor>ga09d177328c5c5e6c43e994048236a1d6</anchor>
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
      <name>kumi::rotate_left</name>
      <anchorfile>group__generators_ga969f4ebe05e88580436080ab956e7e37.html</anchorfile>
      <anchor>ga969f4ebe05e88580436080ab956e7e37</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::rotate_right</name>
      <anchorfile>group__generators_ga7b4c54857ff1b5253b86ae9b05098268.html</anchorfile>
      <anchor>ga7b4c54857ff1b5253b86ae9b05098268</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
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
      <anchorfile>group__generators_ga50bbffc3a4571932d98ffe63499971dd.html</anchorfile>
      <anchor>ga50bbffc3a4571932d98ffe63499971dd</anchor>
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
      <anchorfile>group__generators_ga733dfa174c0e531632cc1b0dd433a593.html</anchorfile>
      <anchor>ga733dfa174c0e531632cc1b0dd433a593</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip</name>
      <anchorfile>group__generators_ga6fcdd03f2a3360cbb976cf05e0b0468c.html</anchorfile>
      <anchor>ga6fcdd03f2a3360cbb976cf05e0b0468c</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_max</name>
      <anchorfile>group__generators_gad2b81bc979a4089affddfdbef866e80b.html</anchorfile>
      <anchor>gad2b81bc979a4089affddfdbef866e80b</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_min</name>
      <anchorfile>group__generators_ga90d498013e5f387b2c906a4184644979.html</anchorfile>
      <anchor>ga90d498013e5f387b2c906a4184644979</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
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
    <concept>kumi::concepts::product_type</concept>
    <concept>kumi::concepts::record_type</concept>
    <concept>kumi::concepts::static_container</concept>
    <concept>kumi::concepts::unit_type</concept>
    <concept>kumi::concepts::sized_product_type</concept>
    <concept>kumi::concepts::sized_product_type_or_more</concept>
    <concept>kumi::concepts::empty_product_type</concept>
    <concept>kumi::concepts::non_empty_product_type</concept>
    <concept>kumi::concepts::index_map</concept>
    <concept>kumi::concepts::indexer</concept>
    <concept>kumi::concepts::homogeneous_product_type</concept>
    <concept>kumi::concepts::equality_comparable</concept>
    <concept>kumi::concepts::has_named_fields</concept>
    <concept>kumi::concepts::is_fully_named</concept>
    <concept>kumi::concepts::uniquely_typed</concept>
    <concept>kumi::concepts::uniquely_named</concept>
    <concept>kumi::concepts::entirely_uniquely_named</concept>
    <concept>kumi::concepts::contains_type</concept>
    <concept>kumi::concepts::contains_field</concept>
    <concept>kumi::concepts::equivalent</concept>
    <concept>kumi::concepts::named_equality_comparable</concept>
    <concept>kumi::concepts::follows_same_semantic</concept>
    <concept>kumi::concepts::compatible_product_types</concept>
    <concept>kumi::concepts::monoid</concept>
    <concept>kumi::_::std_tuple_compatible</concept>
  </compound>
  <compound kind="group">
    <name>traits</name>
    <title>Tuple Related Traits</title>
    <filename>group__traits.html</filename>
    <class kind="struct">kumi::all_unique_names</class>
    <class kind="struct">kumi::all_uniques</class>
    <class kind="struct">kumi::common_product_type</class>
    <class kind="struct">kumi::container_size</class>
    <class kind="struct">kumi::container_type</class>
    <class kind="struct">kumi::element</class>
    <class kind="struct">kumi::is_homogeneous</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::is_record_type</class>
    <class kind="struct">kumi::is_static_container</class>
    <class kind="struct">kumi::member</class>
    <class kind="struct">kumi::raw_element</class>
    <class kind="struct">kumi::raw_member</class>
    <class kind="struct">kumi::size</class>
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
      <anchorfile>group__transforms_ga570ad42b8992ce6096c05dd6b2bbcf6d.html</anchorfile>
      <anchor>ga570ad42b8992ce6096c05dd6b2bbcf6d</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t) noexcept(_::supports_nothrow_apply&lt; Function &amp;&amp;, T &amp;&amp; &gt;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each</name>
      <anchorfile>group__transforms_gacfc6eb17686b7570f768de71198d8812.html</anchorfile>
      <anchor>gacfc6eb17686b7570f768de71198d8812</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_field</name>
      <anchorfile>group__transforms_gab51ac1793c12bbc1b1979bc0b51eb33a.html</anchorfile>
      <anchor>gab51ac1793c12bbc1b1979bc0b51eb33a</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_index</name>
      <anchorfile>group__transforms_ga1e4f9df80b8d396b32e2f5d3316caea9.html</anchorfile>
      <anchor>ga1e4f9df80b8d396b32e2f5d3316caea9</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map</name>
      <anchorfile>group__transforms_ga5fb0d0c6af4d4c1a814e5bf746f8201a.html</anchorfile>
      <anchor>ga5fb0d0c6af4d4c1a814e5bf746f8201a</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_field</name>
      <anchorfile>group__transforms_ga2096ba88ea732e93bd9025952ae1f9f2.html</anchorfile>
      <anchor>ga2096ba88ea732e93bd9025952ae1f9f2</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_index</name>
      <anchorfile>group__transforms_ga3860b86e65fdb667cb114f575fe3eb75.html</anchorfile>
      <anchor>ga3860b86e65fdb667cb114f575fe3eb75</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>tuple</name>
    <title>Tuple Types and Functions</title>
    <filename>group__tuple.html</filename>
    <class kind="struct">kumi::as_tuple</class>
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
      <anchor>gacebb3ddeaa684e400b25f48849147641</anchor>
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
      <anchorfile>group__tuple_ga1a3be7d170cb81c6f87c93a0a04eabc8.html</anchorfile>
      <anchor>ga1a3be7d170cb81c6f87c93a0a04eabc8</anchor>
      <arglist>(Ts &amp;... ts) -&gt; tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::make_tuple</name>
      <anchorfile>group__tuple_ga98e6c367de0e0f526565280a0856b007.html</anchorfile>
      <anchor>ga98e6c367de0e0f526565280a0856b007</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tuple::forward_as_tuple</name>
      <anchorfile>group__tuple_ga4cc5b452c723ee16fdd9a4de143ef0c1.html</anchorfile>
      <anchor>ga4cc5b452c723ee16fdd9a4de143ef0c1</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tuple::to_ref</name>
      <anchorfile>group__tuple_ga27c29bc9a5e31d7ada4ac427a18d8985.html</anchorfile>
      <anchor>ga27c29bc9a5e31d7ada4ac427a18d8985</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tuple::from_tuple</name>
      <anchorfile>group__tuple_ga5e1b1ae039b6c55ae68e875505d36774.html</anchorfile>
      <anchor>ga5e1b1ae039b6c55ae68e875505d36774</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tuple::to_tuple</name>
      <anchorfile>group__tuple_gafdea058f9f804755e1b3ce010be52f40.html</anchorfile>
      <anchor>gafdea058f9f804755e1b3ce010be52f40</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
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
