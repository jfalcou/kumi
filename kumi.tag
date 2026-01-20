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
    <name>kumi::_::builder</name>
    <filename>structkumi_1_1___1_1builder.html</filename>
    <templarg>kumi::product_type T</templarg>
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
      <name>field_cast</name>
      <anchorfile>group__product__types_ga59477c1d8542af2601f493e3320434ee.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
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
      <anchorfile>structkumi_1_1field__name_a5966f40f6ea3b63c173fd8efd892af0b.html</anchorfile>
      <anchor>a5966f40f6ea3b63c173fd8efd892af0b</anchor>
      <arglist>(T v) const noexcept</arglist>
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
    <templarg>typename Enable</templarg>
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
      <anchorfile>group__record_ga508677aacba8fa46c42516e15c92ab3c.html</anchorfile>
      <anchor>ga508677aacba8fa46c42516e15c92ab3c</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; field_capture&lt; Fields, Ts &amp;&amp; &gt;... &gt;</arglist>
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
      <anchorfile>group__record_gaaa38d1d378b716e24c974facce426d72.html</anchorfile>
      <anchor>gaaa38d1d378b716e24c974facce426d72</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
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
      <anchorfile>structkumi_1_1tuple_a177268aec619b2fc2dd02085b5e44c73.html</anchorfile>
      <anchor>a177268aec619b2fc2dd02085b5e44c73</anchor>
      <arglist>(as&lt; T &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>abe7aa375e2d3da5877cabcb16ddaaaa4</anchor>
      <arglist>(as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8b3ff440507f90b6d78294ba2b934579</anchor>
      <arglist>(as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>acdf560cae3407b301297a4a333ed95d8</anchor>
      <arglist>(as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a761823a07c4e3d8a7aabd3bfb9043ee2.html</anchorfile>
      <anchor>a761823a07c4e3d8a7aabd3bfb9043ee2</anchor>
      <arglist>(field_name&lt; Name &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a48642f2655a07ae69ef64a332ad62f0c</anchor>
      <arglist>(field_name&lt; Name &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a5c7db0cabac5165c874edc859b050e70</anchor>
      <arglist>(field_name&lt; Name &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aeed0eed1cd17796a449ac10c00cbee00</anchor>
      <arglist>(field_name&lt; Name &gt;) const &amp;noexcept</arglist>
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
      <anchorfile>structkumi_1_1tuple_a177268aec619b2fc2dd02085b5e44c73.html</anchorfile>
      <anchor>a177268aec619b2fc2dd02085b5e44c73</anchor>
      <arglist>(as&lt; T &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>abe7aa375e2d3da5877cabcb16ddaaaa4</anchor>
      <arglist>(as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8b3ff440507f90b6d78294ba2b934579</anchor>
      <arglist>(as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>acdf560cae3407b301297a4a333ed95d8</anchor>
      <arglist>(as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a761823a07c4e3d8a7aabd3bfb9043ee2.html</anchorfile>
      <anchor>a761823a07c4e3d8a7aabd3bfb9043ee2</anchor>
      <arglist>(field_name&lt; Name &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a48642f2655a07ae69ef64a332ad62f0c</anchor>
      <arglist>(field_name&lt; Name &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a5c7db0cabac5165c874edc859b050e70</anchor>
      <arglist>(field_name&lt; Name &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aeed0eed1cd17796a449ac10c00cbee00</anchor>
      <arglist>(field_name&lt; Name &gt;) const &amp;noexcept</arglist>
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
      <anchor>ga5544b3b084ae69ad34a4ea0e99a00670</anchor>
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
    <name>kumi::monoid</name>
    <filename>conceptkumi_1_1monoid.html</filename>
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
    <name>kumi::static_container</name>
    <filename>conceptkumi_1_1static__container.html</filename>
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
  <compound kind="concept">
    <name>kumi::unit_type</name>
    <filename>conceptkumi_1_1unit__type.html</filename>
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
    <class kind="struct">kumi::container_size</class>
    <class kind="struct">kumi::container_type</class>
    <class kind="struct">kumi::element</class>
    <class kind="class">kumi::field_capture</class>
    <class kind="class">kumi::field_name</class>
    <class kind="struct">kumi::index_t</class>
    <class kind="class">kumi::indexes_t</class>
    <class kind="struct">kumi::is_homogeneous</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::is_record_type</class>
    <class kind="struct">kumi::is_static_container</class>
    <class kind="struct">kumi::member</class>
    <class kind="class">kumi::numeric_add</class>
    <class kind="class">kumi::numeric_prod</class>
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
    <concept>kumi::static_container</concept>
    <concept>kumi::unit_type</concept>
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
    <concept>kumi::monoid</concept>
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
      <anchorfile>group__generators_ga71ccd933cc34850c94a6c51cb831cbaa.html</anchorfile>
      <anchor>ga71ccd933cc34850c94a6c51cb831cbaa</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cat</name>
      <anchorfile>group__generators_ga75156b6b59e7fa8ac478bf87f1636afc.html</anchorfile>
      <anchor>ga75156b6b59e7fa8ac478bf87f1636afc</anchor>
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
      <name>exclusive_scan_left</name>
      <anchorfile>group__reductions_ga4c7de497ac4fbf84207e8b5249e808a5.html</anchorfile>
      <anchor>ga4c7de497ac4fbf84207e8b5249e808a5</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__reductions_ga7ad77fdfc161a999369fde5f9006d561.html</anchorfile>
      <anchor>ga7ad77fdfc161a999369fde5f9006d561</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__generators_ga5c0915917db751d43c4a07eb884945cc.html</anchorfile>
      <anchor>ga5c0915917db751d43c4a07eb884945cc</anchor>
      <arglist>(T &amp;&amp;t, Func &amp;&amp;f)</arglist>
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
      <anchorfile>group__transforms_gab149989d49d601440eae1057a6065c9b.html</anchorfile>
      <anchor>gab149989d49d601440eae1057a6065c9b</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_field</name>
      <anchorfile>group__transforms_gad3668dcbb21c0f05bba31bef051c6734.html</anchorfile>
      <anchor>gad3668dcbb21c0f05bba31bef051c6734</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_index</name>
      <anchorfile>group__transforms_gaccfc046f0abee0e449ddf6935669bd84.html</anchorfile>
      <anchor>gaccfc046f0abee0e449ddf6935669bd84</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_record</name>
      <anchorfile>group__utility_gaf34b032f903e869b9f63610867f431de.html</anchorfile>
      <anchor>gaf34b032f903e869b9f63610867f431de</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r)</arglist>
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
      <name>inclusive_scan_left</name>
      <anchorfile>group__reductions_ga2593e576e29c20d318f8e763e17c10ff.html</anchorfile>
      <anchor>ga2593e576e29c20d318f8e763e17c10ff</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__reductions_gac4836103eaea033fd6ce5e815d21b69a.html</anchorfile>
      <anchor>gac4836103eaea033fd6ce5e815d21b69a</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t, Value init)</arglist>
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
      <anchor>a720dd1d10d09b5da1758f3bec126584b</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>group__reductions_ga7296647c71126e9dc46767d5a3a203bb.html</anchorfile>
      <anchor>ga7296647c71126e9dc46767d5a3a203bb</anchor>
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
      <anchorfile>group__transforms_ga95273be2688569470df001771d0f6aba.html</anchorfile>
      <anchor>ga95273be2688569470df001771d0f6aba</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_field</name>
      <anchorfile>group__transforms_ga7633017eddbb65a7a7cfd6739cd9bc6e.html</anchorfile>
      <anchor>ga7633017eddbb65a7a7cfd6739cd9bc6e</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_index</name>
      <anchorfile>group__transforms_ga751b47ecd6f9746919370745fdf9515a.html</anchorfile>
      <anchor>ga751b47ecd6f9746919370745fdf9515a</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_reduce</name>
      <anchorfile>group__reductions_ga954395275eacfb5006a6fb84c31707c3.html</anchorfile>
      <anchor>ga954395275eacfb5006a6fb84c31707c3</anchor>
      <arglist>(Function &amp;&amp;f, M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_reduce</name>
      <anchorfile>group__reductions_ga3bdf89343768fdae54a0e33b3240e607.html</anchorfile>
      <anchor>ga3bdf89343768fdae54a0e33b3240e607</anchor>
      <arglist>(Function &amp;&amp;f, M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
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
      <name>operator&quot;&quot;_f</name>
      <anchorfile>group__utility_gac6640fd24bd6244cbed251ed2e689d83.html</anchorfile>
      <anchor>gac6640fd24bd6244cbed251ed2e689d83</anchor>
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
      <name>to_record</name>
      <anchorfile>group__utility_ga324cc6775ad5b15767fc2eaae02abd73.html</anchorfile>
      <anchor>ga324cc6775ad5b15767fc2eaae02abd73</anchor>
      <arglist>(Type &amp;&amp;r)</arglist>
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
      <anchorfile>group__generators_ga8d9c92b3ab597b2fc3454395aefa3800.html</anchorfile>
      <anchor>ga8d9c92b3ab597b2fc3454395aefa3800</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_max</name>
      <anchorfile>group__generators_ga3e199a23061358e19db303266c1fbdb6.html</anchorfile>
      <anchor>ga3e199a23061358e19db303266c1fbdb6</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_min</name>
      <anchorfile>group__generators_gac93f85fe3a0ddf650d8318426ea983d2.html</anchorfile>
      <anchor>gac93f85fe3a0ddf650d8318426ea983d2</anchor>
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
      <anchorfile>group__record_ga684c8e20ee9874bcce628e1c9cec38cb.html</anchorfile>
      <anchor>ga684c8e20ee9874bcce628e1c9cec38cb</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field_capture&lt; Fields, Ts &amp; &gt;... &gt;</arglist>
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
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a9d73e86a7e47b94dfb57f90d11d17a2f</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5582de286453c2e8be2e5cc3d0c9670f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ad1b7b6c47abc71807b4fb85c3f8f80a2</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab65b643f95ecf229b3242dab2a15e591</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a2fecd1a80f1b35ef2c6633fd27229ea1</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>aa87ab35ea8e731ff0f1f5fb0d0c12438</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5589b2ce93dc4ec42fcb4ef9869a0b59</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ad57ff2e8e48896c72e1c93d43ed2c136</anchor>
      <arglist>(R &amp;&amp;r)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab5527f2f9d28b4287d4f6c033deefbfd</anchor>
      <arglist>(T &amp;&amp;t)=delete</arglist>
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
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ad7263a42249d3056aa9e1d6fb4ee5a26</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a72c6a2e978721f6e752a840b90c8f4e3</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>acc03b07f9d777c66f5e853c48702e3df</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5787f20a80465e2bd8bc6b4e97afb4c8</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a7b72992a6ed6da4df4c23230c70d9444</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a17fa33fb013919f49213955bd7f42b8f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>aa6961a7fb905cdffb3debc229f379628</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a9add4a76858bddef8f94c63cc17f9814</anchor>
      <arglist>(T &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>af70256d8cf00d3bd21b666ac6d8da796</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ae927602937c1508fb741abc78e3f22bd</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a063b09cd2e48cd33082ce3642d77121f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a084d37e11fcc9d4874fbac47904bd31e</anchor>
      <arglist>(T &amp;&amp;t)=delete</arglist>
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
      <anchorfile>group__record_ga684c8e20ee9874bcce628e1c9cec38cb.html</anchorfile>
      <anchor>ga684c8e20ee9874bcce628e1c9cec38cb</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field_capture&lt; Fields, Ts &amp; &gt;... &gt;</arglist>
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
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a9d73e86a7e47b94dfb57f90d11d17a2f</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5582de286453c2e8be2e5cc3d0c9670f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ad1b7b6c47abc71807b4fb85c3f8f80a2</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab65b643f95ecf229b3242dab2a15e591</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a2fecd1a80f1b35ef2c6633fd27229ea1</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>aa87ab35ea8e731ff0f1f5fb0d0c12438</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5589b2ce93dc4ec42fcb4ef9869a0b59</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ad57ff2e8e48896c72e1c93d43ed2c136</anchor>
      <arglist>(R &amp;&amp;r)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab5527f2f9d28b4287d4f6c033deefbfd</anchor>
      <arglist>(T &amp;&amp;t)=delete</arglist>
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
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ad7263a42249d3056aa9e1d6fb4ee5a26</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a72c6a2e978721f6e752a840b90c8f4e3</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>acc03b07f9d777c66f5e853c48702e3df</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5787f20a80465e2bd8bc6b4e97afb4c8</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a7b72992a6ed6da4df4c23230c70d9444</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a17fa33fb013919f49213955bd7f42b8f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>aa6961a7fb905cdffb3debc229f379628</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a9add4a76858bddef8f94c63cc17f9814</anchor>
      <arglist>(T &amp;&amp;t)=delete</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>af70256d8cf00d3bd21b666ac6d8da796</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ae927602937c1508fb741abc78e3f22bd</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a063b09cd2e48cd33082ce3642d77121f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a084d37e11fcc9d4874fbac47904bd31e</anchor>
      <arglist>(T &amp;&amp;t)=delete</arglist>
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
    <name>utility</name>
    <title>Helper Types and Functions</title>
    <filename>group__utility.html</filename>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="class">kumi::boolean_and</class>
    <class kind="class">kumi::boolean_or</class>
    <class kind="class">kumi::boolean_xor</class>
    <class kind="class">kumi::field_name</class>
    <class kind="struct">kumi::index_t</class>
    <class kind="class">kumi::indexes_t</class>
    <class kind="class">kumi::numeric_add</class>
    <class kind="class">kumi::numeric_prod</class>
    <class kind="class">kumi::str</class>
    <class kind="class">kumi::unit</class>
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
      <type>constexpr auto</type>
      <name>kumi::from_record</name>
      <anchorfile>group__utility_gaf34b032f903e869b9f63610867f431de.html</anchorfile>
      <anchor>gaf34b032f903e869b9f63610867f431de</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r)</arglist>
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
      <name>kumi::to_record</name>
      <anchorfile>group__utility_ga324cc6775ad5b15767fc2eaae02abd73.html</anchorfile>
      <anchor>ga324cc6775ad5b15767fc2eaae02abd73</anchor>
      <arglist>(Type &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::to_tuple</name>
      <anchorfile>group__utility_gae6de7cdd99f5e217028b93d4bcf3de52.html</anchorfile>
      <anchor>gae6de7cdd99f5e217028b93d4bcf3de52</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
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
      <name>kumi::field_capture::field_cast</name>
      <anchorfile>group__product__types_ga59477c1d8542af2601f493e3320434ee.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
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
      <anchor>ga14b23264019a7e10c1867a16b2c500c0</anchor>
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
      <anchorfile>group__record_ga684c8e20ee9874bcce628e1c9cec38cb.html</anchorfile>
      <anchor>ga684c8e20ee9874bcce628e1c9cec38cb</anchor>
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
      <anchorfile>group__record_gaaa38d1d378b716e24c974facce426d72.html</anchorfile>
      <anchor>gaaa38d1d378b716e24c974facce426d72</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
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
      <anchorfile>group__reductions_ga4c7de497ac4fbf84207e8b5249e808a5.html</anchorfile>
      <anchor>ga4c7de497ac4fbf84207e8b5249e808a5</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__reductions_ga7ad77fdfc161a999369fde5f9006d561.html</anchorfile>
      <anchor>ga7ad77fdfc161a999369fde5f9006d561</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__reductions_ga2593e576e29c20d318f8e763e17c10ff.html</anchorfile>
      <anchor>ga2593e576e29c20d318f8e763e17c10ff</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__reductions_gac4836103eaea033fd6ce5e815d21b69a.html</anchorfile>
      <anchor>gac4836103eaea033fd6ce5e815d21b69a</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__reductions_ga7296647c71126e9dc46767d5a3a203bb.html</anchorfile>
      <anchor>ga7296647c71126e9dc46767d5a3a203bb</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_reduce</name>
      <anchorfile>group__reductions_ga954395275eacfb5006a6fb84c31707c3.html</anchorfile>
      <anchor>ga954395275eacfb5006a6fb84c31707c3</anchor>
      <arglist>(Function &amp;&amp;f, M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_reduce</name>
      <anchorfile>group__reductions_ga3bdf89343768fdae54a0e33b3240e607.html</anchorfile>
      <anchor>ga3bdf89343768fdae54a0e33b3240e607</anchor>
      <arglist>(Function &amp;&amp;f, M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
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
      <anchorfile>group__generators_ga71ccd933cc34850c94a6c51cb831cbaa.html</anchorfile>
      <anchor>ga71ccd933cc34850c94a6c51cb831cbaa</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::cat</name>
      <anchorfile>group__generators_ga75156b6b59e7fa8ac478bf87f1636afc.html</anchorfile>
      <anchor>ga75156b6b59e7fa8ac478bf87f1636afc</anchor>
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
      <anchorfile>group__generators_ga8d9c92b3ab597b2fc3454395aefa3800.html</anchorfile>
      <anchor>ga8d9c92b3ab597b2fc3454395aefa3800</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_max</name>
      <anchorfile>group__generators_ga3e199a23061358e19db303266c1fbdb6.html</anchorfile>
      <anchor>ga3e199a23061358e19db303266c1fbdb6</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_min</name>
      <anchorfile>group__generators_gac93f85fe3a0ddf650d8318426ea983d2.html</anchorfile>
      <anchor>gac93f85fe3a0ddf650d8318426ea983d2</anchor>
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
    <concept>kumi::std_tuple_compatible</concept>
    <concept>kumi::product_type</concept>
    <concept>kumi::record_type</concept>
    <concept>kumi::static_container</concept>
    <concept>kumi::unit_type</concept>
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
    <concept>kumi::monoid</concept>
  </compound>
  <compound kind="group">
    <name>traits</name>
    <title>Tuple Related Traits</title>
    <filename>group__traits.html</filename>
    <class kind="struct">kumi::all_unique_names</class>
    <class kind="struct">kumi::all_uniques</class>
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
      <anchorfile>group__transforms_gab149989d49d601440eae1057a6065c9b.html</anchorfile>
      <anchor>gab149989d49d601440eae1057a6065c9b</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_field</name>
      <anchorfile>group__transforms_gad3668dcbb21c0f05bba31bef051c6734.html</anchorfile>
      <anchor>gad3668dcbb21c0f05bba31bef051c6734</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_index</name>
      <anchorfile>group__transforms_gaccfc046f0abee0e449ddf6935669bd84.html</anchorfile>
      <anchor>gaccfc046f0abee0e449ddf6935669bd84</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map</name>
      <anchorfile>group__transforms_ga95273be2688569470df001771d0f6aba.html</anchorfile>
      <anchor>ga95273be2688569470df001771d0f6aba</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_field</name>
      <anchorfile>group__transforms_ga7633017eddbb65a7a7cfd6739cd9bc6e.html</anchorfile>
      <anchor>ga7633017eddbb65a7a7cfd6739cd9bc6e</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_index</name>
      <anchorfile>group__transforms_ga751b47ecd6f9746919370745fdf9515a.html</anchorfile>
      <anchor>ga751b47ecd6f9746919370745fdf9515a</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;... others)</arglist>
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
      <anchor>ga5544b3b084ae69ad34a4ea0e99a00670</anchor>
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
