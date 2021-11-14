// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: record.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_record_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_record_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_record_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_record_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_record_2eproto;
class Record;
struct RecordDefaultTypeInternal;
extern RecordDefaultTypeInternal _Record_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Record* Arena::CreateMaybeMessage<::Record>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Record final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Record) */ {
 public:
  inline Record() : Record(nullptr) {}
  ~Record() override;
  explicit constexpr Record(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Record(const Record& from);
  Record(Record&& from) noexcept
    : Record() {
    *this = ::std::move(from);
  }

  inline Record& operator=(const Record& from) {
    CopyFrom(from);
    return *this;
  }
  inline Record& operator=(Record&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Record& default_instance() {
    return *internal_default_instance();
  }
  static inline const Record* internal_default_instance() {
    return reinterpret_cast<const Record*>(
               &_Record_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Record& a, Record& b) {
    a.Swap(&b);
  }
  inline void Swap(Record* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Record* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Record* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Record>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Record& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Record& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Record* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Record";
  }
  protected:
  explicit Record(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLegalAddressFieldNumber = 2,
    kNameFieldNumber = 3,
    kTypeOfActivityFieldNumber = 4,
    kYearOfFoundationFieldNumber = 1,
    kForeignEconomicActivityFieldNumber = 5,
  };
  // required string legal_address = 2;
  bool has_legal_address() const;
  private:
  bool _internal_has_legal_address() const;
  public:
  void clear_legal_address();
  const std::string& legal_address() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_legal_address(ArgT0&& arg0, ArgT... args);
  std::string* mutable_legal_address();
  PROTOBUF_NODISCARD std::string* release_legal_address();
  void set_allocated_legal_address(std::string* legal_address);
  private:
  const std::string& _internal_legal_address() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_legal_address(const std::string& value);
  std::string* _internal_mutable_legal_address();
  public:

  // required string name = 3;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // optional string type_of_activity = 4;
  bool has_type_of_activity() const;
  private:
  bool _internal_has_type_of_activity() const;
  public:
  void clear_type_of_activity();
  const std::string& type_of_activity() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_type_of_activity(ArgT0&& arg0, ArgT... args);
  std::string* mutable_type_of_activity();
  PROTOBUF_NODISCARD std::string* release_type_of_activity();
  void set_allocated_type_of_activity(std::string* type_of_activity);
  private:
  const std::string& _internal_type_of_activity() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_type_of_activity(const std::string& value);
  std::string* _internal_mutable_type_of_activity();
  public:

  // required int32 year_of_foundation = 1;
  bool has_year_of_foundation() const;
  private:
  bool _internal_has_year_of_foundation() const;
  public:
  void clear_year_of_foundation();
  int32_t year_of_foundation() const;
  void set_year_of_foundation(int32_t value);
  private:
  int32_t _internal_year_of_foundation() const;
  void _internal_set_year_of_foundation(int32_t value);
  public:

  // optional bool foreign_economic_activity = 5;
  bool has_foreign_economic_activity() const;
  private:
  bool _internal_has_foreign_economic_activity() const;
  public:
  void clear_foreign_economic_activity();
  bool foreign_economic_activity() const;
  void set_foreign_economic_activity(bool value);
  private:
  bool _internal_foreign_economic_activity() const;
  void _internal_set_foreign_economic_activity(bool value);
  public:

  // @@protoc_insertion_point(class_scope:Record)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr legal_address_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr type_of_activity_;
  int32_t year_of_foundation_;
  bool foreign_economic_activity_;
  friend struct ::TableStruct_record_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Record

// required int32 year_of_foundation = 1;
inline bool Record::_internal_has_year_of_foundation() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool Record::has_year_of_foundation() const {
  return _internal_has_year_of_foundation();
}
inline void Record::clear_year_of_foundation() {
  year_of_foundation_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline int32_t Record::_internal_year_of_foundation() const {
  return year_of_foundation_;
}
inline int32_t Record::year_of_foundation() const {
  // @@protoc_insertion_point(field_get:Record.year_of_foundation)
  return _internal_year_of_foundation();
}
inline void Record::_internal_set_year_of_foundation(int32_t value) {
  _has_bits_[0] |= 0x00000008u;
  year_of_foundation_ = value;
}
inline void Record::set_year_of_foundation(int32_t value) {
  _internal_set_year_of_foundation(value);
  // @@protoc_insertion_point(field_set:Record.year_of_foundation)
}

// required string legal_address = 2;
inline bool Record::_internal_has_legal_address() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Record::has_legal_address() const {
  return _internal_has_legal_address();
}
inline void Record::clear_legal_address() {
  legal_address_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Record::legal_address() const {
  // @@protoc_insertion_point(field_get:Record.legal_address)
  return _internal_legal_address();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Record::set_legal_address(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 legal_address_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Record.legal_address)
}
inline std::string* Record::mutable_legal_address() {
  std::string* _s = _internal_mutable_legal_address();
  // @@protoc_insertion_point(field_mutable:Record.legal_address)
  return _s;
}
inline const std::string& Record::_internal_legal_address() const {
  return legal_address_.Get();
}
inline void Record::_internal_set_legal_address(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  legal_address_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Record::_internal_mutable_legal_address() {
  _has_bits_[0] |= 0x00000001u;
  return legal_address_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Record::release_legal_address() {
  // @@protoc_insertion_point(field_release:Record.legal_address)
  if (!_internal_has_legal_address()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  auto* p = legal_address_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (legal_address_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    legal_address_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Record::set_allocated_legal_address(std::string* legal_address) {
  if (legal_address != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  legal_address_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), legal_address,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (legal_address_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    legal_address_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Record.legal_address)
}

// required string name = 3;
inline bool Record::_internal_has_name() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Record::has_name() const {
  return _internal_has_name();
}
inline void Record::clear_name() {
  name_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Record::name() const {
  // @@protoc_insertion_point(field_get:Record.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Record::set_name(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000002u;
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Record.name)
}
inline std::string* Record::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Record.name)
  return _s;
}
inline const std::string& Record::_internal_name() const {
  return name_.Get();
}
inline void Record::_internal_set_name(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Record::_internal_mutable_name() {
  _has_bits_[0] |= 0x00000002u;
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Record::release_name() {
  // @@protoc_insertion_point(field_release:Record.name)
  if (!_internal_has_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  auto* p = name_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Record::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Record.name)
}

// optional string type_of_activity = 4;
inline bool Record::_internal_has_type_of_activity() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool Record::has_type_of_activity() const {
  return _internal_has_type_of_activity();
}
inline void Record::clear_type_of_activity() {
  type_of_activity_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000004u;
}
inline const std::string& Record::type_of_activity() const {
  // @@protoc_insertion_point(field_get:Record.type_of_activity)
  return _internal_type_of_activity();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Record::set_type_of_activity(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000004u;
 type_of_activity_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Record.type_of_activity)
}
inline std::string* Record::mutable_type_of_activity() {
  std::string* _s = _internal_mutable_type_of_activity();
  // @@protoc_insertion_point(field_mutable:Record.type_of_activity)
  return _s;
}
inline const std::string& Record::_internal_type_of_activity() const {
  return type_of_activity_.Get();
}
inline void Record::_internal_set_type_of_activity(const std::string& value) {
  _has_bits_[0] |= 0x00000004u;
  type_of_activity_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Record::_internal_mutable_type_of_activity() {
  _has_bits_[0] |= 0x00000004u;
  return type_of_activity_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Record::release_type_of_activity() {
  // @@protoc_insertion_point(field_release:Record.type_of_activity)
  if (!_internal_has_type_of_activity()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000004u;
  auto* p = type_of_activity_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (type_of_activity_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    type_of_activity_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Record::set_allocated_type_of_activity(std::string* type_of_activity) {
  if (type_of_activity != nullptr) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  type_of_activity_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), type_of_activity,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (type_of_activity_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    type_of_activity_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Record.type_of_activity)
}

// optional bool foreign_economic_activity = 5;
inline bool Record::_internal_has_foreign_economic_activity() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool Record::has_foreign_economic_activity() const {
  return _internal_has_foreign_economic_activity();
}
inline void Record::clear_foreign_economic_activity() {
  foreign_economic_activity_ = false;
  _has_bits_[0] &= ~0x00000010u;
}
inline bool Record::_internal_foreign_economic_activity() const {
  return foreign_economic_activity_;
}
inline bool Record::foreign_economic_activity() const {
  // @@protoc_insertion_point(field_get:Record.foreign_economic_activity)
  return _internal_foreign_economic_activity();
}
inline void Record::_internal_set_foreign_economic_activity(bool value) {
  _has_bits_[0] |= 0x00000010u;
  foreign_economic_activity_ = value;
}
inline void Record::set_foreign_economic_activity(bool value) {
  _internal_set_foreign_economic_activity(value);
  // @@protoc_insertion_point(field_set:Record.foreign_economic_activity)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_record_2eproto
